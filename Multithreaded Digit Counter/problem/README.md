# Multithreaded Digit Counter

**Problem Statement:**
Write a C program that receives multiple strings as command-line arguments, where each string contains space-separated integers (e.g., `"10 20 -30"`). The program must spawn one thread per input string. Each thread is responsible for parsing its assigned string's numbers, counting the total number of digits across all those numbers, and adding this count to a shared long accumulator. The main thread must wait for all threads to complete and then print the overall sum. 

*Note: Solutions that do not employ threads and proper synchronization (e.g., mutexes) will not receive credit.*

**Example Execution:**
```bash
./a.out "1 2 4 5" "1 2 5 1 4" "1 5 1 2 5" "1 2 4 1 5" "1 15 12 22"

```

**Expected Output:**

```text
26
```
