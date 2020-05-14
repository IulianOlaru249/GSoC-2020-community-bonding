# GSoC-2020-community-bonding
A few tasks received during the community bonding period of GSoC 2020.

## Simple Unix I/O operrations


Unix file descriptor = integer indexing a table with pointers to structures 
describing files opened by a process.
Whenever a process starts, its parent opens 3 standart files with standard fd's:
        - stdin(0)
        - stdout(1)
        - stderr(2)

```bash
Create, Open and Close files.
Read and Write.
Positioning in files.
Truncate.
Redirecting.
```
