#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define NAME "socket"

int main() {
    int sock, len;
    struct sockaddr_un name;
    char buf[1024];

    sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("SOCKET");
        exit(1);
    }

    name.sun_family = AF_UNIX;
    strcpy(name.sun_path, NAME);

    if (bind(sock, (struct sockaddr *) &name, sizeof(struct sockaddr_un))) {
        perror("BIND");
        exit(1);
    }
    printf("socket -->%s\n", NAME);

    if (read(sock, buf, 1024) < 0)
        perror("READ");
    printf("-->%s\n", buf);
    close(sock);
    unlink(NAME);
}
