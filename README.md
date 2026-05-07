# OSproblems

Welcome to the **OSproblems** repository! This project contains a collection of OS problems and their corresponding C implementations. 


<!-- It serves as a practical guide to understanding core system-level programming concepts such as process management, file I/O, and command-line argument parsing. -->


---

## Repository Structure

Each specific problem is housed in its own root-level directory. 

Inside every challenge directory, you will find two sub-directories:
*   `problem/`: Contains the detailed problem statement, requirements, and expected output (README.md).
*   `solution/`: Contains the C source code implementation that solves the problem.

### Visual Layout

```text
OSproblems
 ┣ Parsing Flags in C
 ┃ ┣ problem
 ┃ ┃ ┗ README.md
 ┃ ┗ solution
 ┃   ┗ main.c
 ┣ Print PIDs
 ┃ ┣ problem
 ┃ ┃ ┗ README.md
 ┃ ┗ solution
 ┃   ┗ main.c
 ┣ Multi-Process Exit Codes
 ┃ ┣ problem
 ┃ ┃ ┗ README.md
 ┃ ┗ solution
 ┃   ┗ main.c
 ┣ README.md
 ┗ SyscallsDoc.md
```

---

##  Documentation

At the root of this repository, you will find [**`SyscallsDoc.md`**](./SyscallsDoc.md). 

This file is a quick-reference guide and documentation for the most common C/POSIX headers and functions related to operating systems programming. 

---

## Getting Started

### Prerequisites
To compile and run the solutions in this repository, you will need a Unix-like environment (Linux or macOS) with a C compiler installed (such as `gcc` or `clang`).

### Compiling a Solution
Navigate to the specific solution directory you want to run and use your C compiler. For example, using `gcc`:

```bash
# Navigate to the solution directory
cd Parsing Flags in C/solution/

# Compile the C file
gcc main.c -o solution
```

### Running the Executable
Once compiled, you can run the output file. If the problem requires command-line arguments, pass them during execution:

```bash
# Run without arguments
./solution

# Run with arguments (example)
./solution -x "TestValue" -y -z 
```

