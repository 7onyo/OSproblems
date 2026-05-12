# Two-Way Pipe Cipher

**Problem Statement:**
Create a C application that spawns two child processes which communicate with each other using pipes. If no arguments are provided at execution, the program must print `Error: no argument found` to STDOUT and exit with code `0`.

**Requirements:**
* **First Subprocess:**
  * Reads all command-line arguments (strings representing words) and concatenates them into a single message separated by spaces.
  * Applies a character substitution transformation:
    * Each lowercase letter (`a`–`z`) is replaced by the next letter in the alphabet (`z` becomes `a`).
    * Each uppercase letter (`A`–`Z`) is replaced by the previous letter in the alphabet (`A` becomes `Z`).
    * All other characters remain unchanged.
  * Sends the transformed message through a pipe to the second subprocess.
  * After receiving the message back from the second subprocess, compares it with the original concatenated message. If identical, it prints: `Communication successful`, otherwise `Communication failed`.
* **Second Subprocess:**
  * Reads the message from the first pipe.
  * Applies the inverse transformation to recover the original message.
  * Prints the message to standard output. *(Note: The example output shows the transformed message being printed).*
  * Sends the recovered message back to the first subprocess through a second pipe.

**Example Execution:**
```bash
./a.out abcd AbCd abtd3 q-t3

```

**Expected Output:**

```text
bcde ZcBe bcue3 r-u3
Communication successful

```

