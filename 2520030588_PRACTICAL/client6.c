#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    char msg[100];

    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);

    int fd1 = open("fifo1", O_WRONLY);
    write(fd1, msg, sizeof(msg));
    close(fd1);

    int fd2 = open("fifo2", O_RDONLY);
    read(fd2, msg, sizeof(msg));
    close(fd2);

    printf("Server Reply: %s\n", msg);

    return 0;
}
