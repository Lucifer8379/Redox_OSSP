Operating Systems Lab – Practical 4
Aim
To create multiple child processes using fork() and synchronize them using wait() and waitpid(). To create a zombie process, observe it in the process table, and eliminate it using proper synchronization.

Programs Included
1. wait_compare.c
Creates multiple child processes and demonstrates the difference between wait() and waitpid().

2. zombie.c
Creates a zombie process by allowing the child process to terminate while the parent delays calling wait().

3. no_zombie.c
Eliminates the zombie process using proper synchronization with wait().

Compilation and Execution
wait() and waitpid()
nano wait_compare.c
gcc wait_compare.c
./a.out
Zombie Process
nano zombie.c
gcc zombie.c
./a.out
Remove Zombie Process
nano no_zombie.c
gcc no_zombie.c
./a.out
View Zombie Process
ps -el | grep Z
Description
Process Synchronization
The parent creates multiple child processes using fork().
wait() waits for any child process to terminate.
waitpid() waits for a specific child process using its PID.
Both methods synchronize the parent and child processes.
Zombie Process
The child process terminates immediately.
The parent remains active without collecting the child's exit status.
The terminated child appears as a zombie (Z) in the process table.
Removing the Zombie
The parent calls wait().
The child's exit status is collected.
The zombie entry is removed from the process table.
System Calls Used
fork()
wait()
waitpid()
sleep()
exit()
getpid()
Outcome
Successfully implemented process synchronization using wait() and waitpid().
Created and observed a zombie process.
Eliminated the zombie process using proper synchronization.
