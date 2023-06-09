#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DATA "Hoy es viernes. Todo el dia. . ."

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_un name;

    if (argc != 3) {
        printf ("USO: %s <path de archivo UNIX> <msg>\n", argv[0]);
        exit (1);
    }

    sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("SOCKET");
        exit(1);
    }
    
    name.sun_family = AF_UNIX;
    strcpy(name.sun_path, argv[1]);
    
    //if (sendto(sock, DATA, sizeof(DATA), 0, (struct sockaddr *)&name, sizeof(struct sockaddr_un)) < 0) {
    if (sendto(sock, argv[2], strlen(argv[2]) + 1, 0, (struct sockaddr *)&name, sizeof(struct sockaddr_un)) < 0) {
        perror("SENDTO");
    }
    close(sock);
}
