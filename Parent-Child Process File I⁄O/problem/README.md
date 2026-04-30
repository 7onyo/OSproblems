# Parent-Child Process File I/O

**Problem Statement:**
Create a C application capable of reading from and writing to a specific file. The filename and the content to be written will be provided as command-line arguments at execution.

**Requirements:**
* The application must create a subprocess. 
* The **child process** is responsible for writing the received command-line arguments into the file.
* The **parent process** must read the contents of the newly written file and print the information to the standard output (`STDOUT`).

**Example Usage:**
```bash
./a.out filename Today is sunny
```

**Expected Output:** 
Both the standard output and the file `filename` should contain: 
`Todayissunny`