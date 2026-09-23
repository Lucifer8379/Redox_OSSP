#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int i;
    pid_t pid;

    for(i = 1; i <= 3; i++) {
        pid = fork();

        if(pid == 0) {
            printf("Child %d : PID = %d\n", i, getpid());
            sleep(i);   // Different finishing times
            printf("Child %d finished\n", i);
            exit(0);
        }
    }

    printf("Parent PID = %d\n", getpid());

    // wait() - waits for any child
    for(i = 1; i <= 2; i++) {
        wait(NULL);
        printf("Parent collected one child using wait()\n");
    }

    // waitpid() - waits for remaining specific child
    waitpid(pid, NULL, 0);
    printf("Parent collected last child using waitpid()\n");

    return 0;
}
