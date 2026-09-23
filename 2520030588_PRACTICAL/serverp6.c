#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char msg[100];
    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    while(1) {
        int fd1 = open("fifo1", O_RDONLY);
        read(fd1, msg, sizeof(msg));
        close(fd1);

        printf("Client: %s\n", msg);

        strcat(msg, " [Received by Server]");

        int fd2 = open("fifo2", O_WRONLY);
        write(fd2, msg, sizeof(msg));
        close(fd2);
    }

    return 0;
}
