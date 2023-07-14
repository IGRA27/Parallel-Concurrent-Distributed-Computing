#include <stdlib.h>
#include <stdio.h>

/* Impresion de poema de Neftali Reyes Basoalto
 * SEGUNDA VERSION - SIN CONTROL DE CONRURRENCIA, UTILIZA "SLEEP"
 * Trabajan cinco procesos
 * Los procesos se turnan para imprimir las lineas de cada estrofa
 */

// EL PRIMER PROCESO IMPRIME LAS PRIMERAS LINEAS DE CADA ESTROFA
char *pr1[] = {
    "1.1 Me gustas cuando callas porque estas como ausente,\n",
    "2.1 Como todas las cosas estan llenas de mi alma\n",
    "3.1 Me gustas cuando callas y estas como distante.\n",
    "4.1 Dejame que te hable tambien con tu silencio\n",
    "5.1 Me gustas cuando callas porque estas como ausente.\n"
};

// EL SEGUNDO PROCESO IMPRIME LAS SEGUNDAS LINEAS DE CADA ESTROFA
char *pr2[] = {
    "1.2 y me oyes desde lejos, y mi voz no te toca.\n",
    "2.2 emerges de las cosas, llena del alma mia.\n",
    "3.2 Y estas como quejandote, mariposa en arrullo.\n",
    "4.2 claro como una lampara, simple como un anillo.\n",
    "5.2 Distante y dolorosa como si hubieras muerto.\n"
};

char *pr3[] = {
    "1.3 Parece que los ojos se te hubieran volado\n",
    "2.3 Mariposa de sueno, te pareces a mi alma,\n",
    "3.3 Y me oyes desde lejos, y mi voz no te alcanza:\n",
    "4.3 Eres como la noche, callada y constelada.\n",
    "5.3 Una palabra entonces, una sonrisa bastan.\n"
};

char *pr4[] = {
    "1.4 y parece que un beso te cerrara la boca.\n",
    "2.4 y te pareces a la palabra melancolia.\n",
    "3.4 dejame que me calle con el silencio tuyo.\n",
    "4.4 tu silencio es de estrella, tan lejano y sencillo.\n",
    "5.4 Y estoy alegre, alegre de que no sea cierto.\n"
};

main (argc, argv)
int argc;
char *argv[];
{
  int i;
  int nl;

  if (argc != 2) {
    printf ("USO: %s <numero de estrofas>\n", argv[0]);
    exit (1);
  }

  nl = atoi(argv[1]);

  if (fork() == 0) { /* primer proceso */
    for (i = 0; i < nl; i++) {
      sleep (1);
      printf ("%s", pr1[i]);
    }
    exit (0);
  }
  if (fork () == 0) {  /* segundo proceso */
    for (i = 0; i < nl; i++) {
      sleep (1);
      printf ("%s", pr2[i]);
    }
    exit (0);
  }
  if (fork() == 0) { /* tercer proceso */
    for (i = 0; i < nl; i++) {
      sleep (1);
      printf ("%s", pr3[i]);
    }
    exit (0);
  }
  if (fork () == 0) {  /* cuarto proceso */
    for (i = 0; i < nl; i++) {
      sleep (1);
      printf ("%s", pr4[i]);
    }
    exit (0);
  }
  /* quinto proceso */
  for (i = 1; i <= nl; i++) {
    sleep (1);
    printf ("%d.5\n", i);
  }
    exit (0);
}
