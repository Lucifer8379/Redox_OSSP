Aim
To implement inter-process communication using Named Pipes (FIFOs) in a client–server model and to demonstrate asynchronous event handling using POSIX signal handlers.

Programs Included
1. serverp6.c
The server creates named pipes (FIFOs), receives messages from the client, processes them, and sends a response back through another FIFO.

2. clientp6.c
The client accepts a message from the user, sends it to the server through the FIFO, and displays the reply received from the server.

3. signal_handler.c
This program captures the POSIX signals SIGINT, SIGTERM, and SIGUSR1 using signal handlers and demonstrates asynchronous event handling.

Compilation and Execution
FIFO Server
nano serverp6.c
gcc serverp6.c
./a.out
FIFO Client
nano clientp6.c
gcc clientp6.c
./a.out
POSIX Signal Handling
nano signal_handler.c
gcc signal_handler.c
./a.out
Description
Named Pipe (FIFO) Communication
The server creates two named pipes using mkfifo().
The client writes a message into the first FIFO.
The server reads the message, processes it, and appends a confirmation string.
The modified message is sent back to the client through the second FIFO.
This demonstrates full-duplex communication between two independent processes.
FIFO Behavior with Multiple Clients
Multiple clients can communicate with the same server using the FIFO.
Messages are delivered in the order they are written.
The server processes one request at a time, ensuring sequential communication.
FIFOs provide reliable inter-process communication between unrelated processes.
POSIX Signal Handling
The program registers signal handlers using the signal() system call.

SIGINT – Generated when the user presses Ctrl + C; the handler captures the interrupt signal.
SIGTERM – Sent using the kill command to terminate the process gracefully.
SIGUSR1 – A user-defined signal used for custom asynchronous events.
Signal handlers allow the process to respond immediately whenever a signal is received without continuously checking for events.

System Calls Used
mkfifo()
open()
read()
write()
close()
fork()
signal()
kill()
getpid()
Outcome
Successfully implemented a client–server communication system using Named Pipes (FIFOs).
Demonstrated message exchange between client and server.
Observed FIFO behavior during communication.
Successfully captured and handled SIGINT, SIGTERM, and SIGUSR1.
Demonstrated asynchronous event handling using POSIX signal handlers.
