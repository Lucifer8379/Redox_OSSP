Aim
To implement a Producer–Consumer communication system using anonymous pipes and to execute the equivalent shell command ls -l | grep ".c" using fork(), pipe(), dup2(), and exec().

Programs Included
1. producer_consumer.c
Implements communication between a parent (producer) and child (consumer) using an anonymous pipe.

2. pipe_exec.c
Implements the shell pipeline ls -l | grep ".c" using Linux system calls.

Compilation and Execution
Producer–Consumer
nano producer_consumer.c
gcc producer_consumer.c
./a.out
Shell Pipeline
nano pipe_exec.c
gcc pipe_exec.c
./a.out
Description
Producer–Consumer using Anonymous Pipe
The parent process acts as the producer.
The child process acts as the consumer.
Data is transferred through an anonymous pipe using write() and read().
Communication time is measured to observe IPC efficiency.
Shell Command Implementation
The program executes the equivalent of:

ls -l | grep ".c"
pipe() creates a communication channel.
fork() creates child processes.
dup2() redirects standard input and output.
exec() replaces the child processes with ls and grep.
System Calls Used
fork()
pipe()
dup2()
read()
write()
exec()
wait()
Outcome
Successfully implemented Producer–Consumer communication using anonymous pipes.
Measured inter-process communication efficiency.
Successfully executed the shell pipeline using fork(), pipe(), dup2(), and exec().
