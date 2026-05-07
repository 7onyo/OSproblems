# Multi-Process Exit Codes

**Problem Statement:**
Write a C program for UNIX that creates 20 processes (including the parent). Each child process will immediately terminate returning a unique exit value. The parent process must keep track of its children's PIDs, wait for each specific child to finish, and print the child's sequence number, its PID, and the exit code it returned. After all child processes have been waited on and terminated, the parent will print its own PID and PPID.
