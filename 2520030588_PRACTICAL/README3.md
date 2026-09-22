System calls used: fork() Creates a child process getpid() Returns the Process ID (PID) getppid() Returns the Parent Process ID (PPID)

Process States:

1.Ready State The process is prepared to execute and is waiting for CPU time from the scheduler.
2.Running State The process is currently being executed by the CPU.
3.Waiting State The process is waiting for an event or resource. For example, a parent process calling wait() enters a waiting state until its child process finishes.
4.Terminated State The process has completed its execution and exits the system.
Tools used : ps – displays information about currently running processes and their states. top – provides real-time information about processes and their resource usage. /proc – provides detailed information about processes through the /proc/PID/ directory.
