# Print PIDs

**Problem Statement:**
Write a C program using the `fork()` system call to create a child process. The child process must print its own Process ID (PID) and its parent's PID (PPID). The parent process must wait for the child to finish, then print its own PID and PPID. Finally, ensure the program handles `fork()` failures by safely exiting with an error message.
