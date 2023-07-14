// Programa con variables condicionales
// El hilo inicial (main) crea dos hilos: threadA y threadB y espera por el hilo que finalice primero.
// El hilo inicial (main) finaliza despues de enterarse de la finalizacion del primer hilo
// LOs hilos threadA y threadB duermen un numero "randomico" de segundos (entre 0 y 4 secs) y finalizan
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myConVar = PTHREAD_COND_INITIALIZER;
int threadid = 0;

void * threadA(void *p) {
  sleep(rand() % 5);
  pthread_mutex_lock(&my_mutex);
  threadid = 1;
  pthread_cond_signal(&myConVar);
  pthread_mutex_unlock(&my_mutex);
}

void * threadB(void *p) {
  sleep(rand() % 5);
  pthread_mutex_lock(&my_mutex);
  threadid = 2;
  pthread_cond_signal(&myConVar);
  pthread_mutex_unlock(&my_mutex);
}

int main(int argc, char** argv) {
  srand(time(0));
  pthread_t pthreadA;
  pthread_create(&pthreadA, NULL, threadA, NULL);
  pthread_t pthreadB;
  pthread_create(&pthreadB, NULL, threadB, NULL);
  pthread_mutex_lock(&my_mutex);
  while (threadid == 0)
    pthread_cond_wait(&myConVar, &my_mutex);
  printf("%d\n", threadid);
  pthread_mutex_unlock(&my_mutex);
  return (EXIT_SUCCESS);
}