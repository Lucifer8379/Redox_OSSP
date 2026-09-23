#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig) {
    if(sig == SIGINT)
        printf("\nSIGINT received (Ctrl+C)\n");

    else if(sig == SIGTERM) {
        printf("\nSIGTERM received\n");
        exit(0);
    }

    else if(sig == SIGUSR1)
        printf("\nSIGUSR1 received\n");
}

int main() {
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGUSR1, handler);

    printf("Process ID: %d\n", getpid());

    while(1) {
        printf("Running...\n");
        sleep(3);
    }

    return 0;
}
