#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if(pid == 0) {
        printf("Child Process PID: %d\n", getpid());
        printf("Child exiting...\n");
        exit(0);
    }
    else {
        printf("Parent PID: %d\n", getpid());
        printf("Sleeping for 30 seconds...\n");
        sleep(30);      // Parent does not wait
        printf("Parent exiting\n");
    }

    return 0;
}
