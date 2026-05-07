# Parsing Flags in C2

**Problem Statement:**
Implement a C program using `getopt` to process three options (`-a`, `-b`, `-c <value>`). Include custom error handling to replace default warnings for invalid options and missing arguments. The program must print the resulting flag states, followed by a list of all trailing, non-option arguments passed by the user.

## Here are some examples of using the program:
```bash
// % testopt
// aflag = 0, bflag = 0, cvalue = (null)

// % testopt -a -b
// aflag = 1, bflag = 1, cvalue = (null)

// % testopt -ab
// aflag = 1, bflag = 1, cvalue = (null )

// % testopt -c foo
// aflag = 0, bflag = 0, cvalue = foo

// % testopt -cfoo
// aflag = 0, bflag = 0, cvalue = foo

// % testopt arg1
// aflag = 0, bflag = 0, cvalue = (null)
// Non-option argument arg1

// % testopt -a arg1
// aflag = 1, bflag = 0, cvalue = (null)
// Non-option argument arg1

// % testopt -c foo arg1
// aflag = 0, bflag = 0, cvalue = foo
// Non-option argument arg1

// % testopt -a -- -b
// aflag = 1, bflag = 0, cvalue = (null)
// Non-option argument -b

// % testopt -a -
// aflag = 1, bflag = 0, cvalue = (null)
// Non-option argument -
```