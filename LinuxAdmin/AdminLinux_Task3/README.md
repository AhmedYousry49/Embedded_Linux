AdminLinux Task3
=======

# Section 1:

## 1. Bash script

```bash
#!/bin/bash
BASHRC_FILE="$HOME/.bashrc"
# Check if the .bashrc file exists
if [ -f "$BASHRC_FILE" ]; then
    # Append environment variables to the .bashrc file
    echo "export HELLO=\${HOSTNAME}" >> ${BASHRC_FILE}
    echo "export LOCAL=\$(whoami)" >> ${BASHRC_FILE}
    echo "Environment variables HELLO and LOCAL have been added to .bashrc."
  else
    echo ".bashrc not found in the home directory."
fi
```
 
# Section 2:
## 1. List dir in file 

ls >  /tmp/commands.list



Here's what happens in each case:

---

### a. `cat filename1 | cat filename2`
- **Explanation**: The `|` operator pipes the output of the first command into the input of the second command.
- **Behavior**: The first `cat filename1` outputs the contents of `filename1`. However, the second `cat filename2` does not take input from the pipe; it simply prints the contents of `filename2`.
- **Result**: 
  - The contents of `filename1` will be ignored.
  - Only the contents of `filename2` will be displayed.
- **Effective Equivalent**: `cat filename2`.

---

### b. `ls | rm`
- **Explanation**: ;
  - `ls` lists the files and directories in the current directory.
  - `rm` is the command to remove files or directories.
  - Here, the output of `ls` is piped into `rm`.
- **Behavior**: `rm` expects filenames as arguments, not input from a pipe. The pipe has no effect in this context.
- **Result**: 
  - `rm` will throw an error like: `rm: missing operand` or similar because it didn't receive valid arguments.
  - The command does **not** delete anything.

---

### c. `ls /etc/passwd | wc -l`
- **Explanation**: 
  - `ls /etc/passwd` lists the file `/etc/passwd`.
  - `wc -l` counts the number of lines in its input.
- **Behavior**: 
  - Since `/etc/passwd` is a single file, `ls /etc/passwd` outputs just its name, resulting in **one line** of output.
  - `wc -l` will count that single line.
- **Result**: The output will be `1`.

---


## Search for all files named ".profile"

```bash
#!/bin/bash
find / -name ".profile" 2>/dev/null
```
```bash
#!/bin/bash
bash
ls -i / /etc /etc/hosts
```


```bash
#!/bin/bash
ln -s /etc/passwd /boot/passwd
```

```bash
#!/bin/bash
ln /etc/passwd /boot/passwd
```