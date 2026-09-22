#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
int pid;
char command[20];
printf("Enter a Linux command: ");
scanf("%s", command);
pid = fork();
if(pid < 0)
{
printf("Fork not successful\n");
}
else if(pid == 0)
{
printf("\nChild process\n");
printf("Child PID = %d\n", getpid());
printf("Parent PID = %d\n", getppid());
execlp(command, command, NULL);
printf("Command execution failed\n");
}
else
{
printf("\nParent process\n");
printf("Parent PID = %d\n", getpid());
wait(NULL);
printf("Child process completed\n");
}
return 0;
}
