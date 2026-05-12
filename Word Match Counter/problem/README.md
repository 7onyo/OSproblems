# Word Match Counter

**Problem Statement:**
Write a C program that counts the number of lines containing a specific target word within given files. The target word will be provided as the first command-line argument, and the target files will be provided as the subsequent command-line arguments. The program must output the total number of matching lines for each individual file.

**Example Files:**

`file1`:
```text
this is a test
no match here
test123
TEST

```

*(Matches: "this is a test", "test123" → 2 lines)*

`file2`:

```text
nothing
here

```

*(Matches: 0 lines)*

**Example Execution:**

```bash
./a.out test file1 file2

```

**Expected Output:**

```text
2
0

```
