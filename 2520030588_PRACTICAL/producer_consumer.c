#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if(pid > 0) {              // Parent = Producer
        close(fd[0]);

        char data[100];
        clock_t start = clock();

        for(int i = 1; i <= 5; i++) {
            sprintf(data, "Data %d", i);
            write(fd[1], data, sizeof(data));
            printf("Produced: %s\n", data);
        }

        close(fd[1]);
        wait(NULL);

        clock_t end = clock();
        double t = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Communication Time: %.6f sec\n", t);
    }
    else {                     // Child = Consumer
        close(fd[1]);

        char buffer[100];

        while(read(fd[0], buffer, sizeof(buffer)) > 0) {
            printf("Consumed: %s\n", buffer);
        }

        close(fd[0]);
    }

    return 0;
}
