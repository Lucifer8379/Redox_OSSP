#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if(pid == 0) {
        printf("Child PID: %d\n", getpid());
        exit(0);
    }
    else {
        printf("Parent waiting...\n");
        wait(NULL);
        printf("Zombie removed. Child collected.\n");
    }

    return 0;
}
