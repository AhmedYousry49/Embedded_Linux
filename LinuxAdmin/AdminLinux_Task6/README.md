AdminLinux Task6
=======

# Section 1:

## 1. myteam in your home directory and change its permissions to read only for the owner

```bash

mkdir ~/myteam

chmod 400 ~/myteam

```
## 2. Log out and log in by another user
```bash
sudo username 

```
## 3. Try to access (by cd command) the folder (myteam)

```bash



mkdir ~/myteam  => Permission denied


```


### **a. Change the permissions of the `oldpasswd` file to give owner read and write permissions, group write and execute permissions, ad execute only for others.**

#### Method 1: Using symbolic notation:
```bash
chmod 631 oldpasswd

```

#### Method 2: Using octal notation:
```bash
chmod 751 oldpasswd
```

### **b. Change your default permissions to be as above.**
```bash
umask 026
```

After modifying `~/.bashrc`, run:
```bash
source ~/.bashrc
```

---

### **c. What is the maximum permission a file can have, by default, when it is just created? And what is that for a directory?**

- By default, **a file** will have the maximum permission `666` (rw-rw-rw-), but the system's umask typically reduces this to something like `644` (rw-r--r--), depending on your system's configuration.
  
- By default, **a directory** will have the maximum permission `777` (rwxrwxrwx), but it’s often restricted by the system's umask, typically reducing it to something like `755` (rwxr-xr-x).

---

### **d. Change your default permissions to be no permission to everyone then create a directory and a file to verify.**
```bash
umask 0777
```

Then create a file and a directory to verify:

```bash
touch testfile
mkdir testdir
```

Now check the permissions for the file and directory:

```bash
ls -l testfile testdir
```

### **e. State who can access this file if any with proof.**
---

### **5. Create a file with permission `444`. Try to edit it and remove it? Note what happened.**

#### Create the file with permission `444`:
```bash
touch readonlyfile
chmod 444 readonlyfile
```
