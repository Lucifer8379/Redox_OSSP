#include <stdio.h>
#include <unistd.h>
int main()
{
int pid;
printf("Before fork()\n");
printf("PID: %d\n", getpid());
printf("PPID: %d\n", getppid());
printf("Process State: Running\n");
pid = fork();
if(pid < 0)
{
printf("Fork failed\n");
}
if(pid == 0)
{
printf("\nChild Process\n");
printf("PID: %d\n", getpid());
printf("PPID: %d\n", getppid());
printf("Process State: Running\n");
}
else
{
printf("\nParent Process\n");
printf("PID: %d\n", getpid());
printf("PPID: %d\n", getppid());
printf("Child PID: %d\n", pid);
printf("Process State: Running\n");
}
return 0;
}
