AdminLinux Task2
=======

### Question 1 & Question 2
![alt text](binary_search.png "Title")

# System Information

## 1. List of Available Shells

To list the available shells on your system, you can use the following command in your terminal:

```bash
cat /etc/shells
```

This will display the list of installed shells. Commonly available shells include:
- `/bin/bash` (Bash)
- `/bin/zsh` (Zsh)
- `/bin/dash` (Dash)
- `/bin/fish` (Fish Shell)

## 2. List of Environment Variables in Your Current Shell

To view the environment variables in your current shell, run:

```bash
printenv
```

Alternatively, you can use the `env` command:

```bash
env
```

This will display all environment variables set in the current shell. Some common environment variables include:
- `PATH`
- `HOME`
- `USER`
- `SHELL`
- `PWD`

## 3. Display Your Current Shell Name

To display the name of your current shell, use the following command:

```bash
echo $SHELL
```

This will output the path of the current shell, such as:
- `/bin/bash`
  

# Shell Commands and Alias

## 1. Purpose of the `\` Character in `echo \`

When you execute the following command:

```bash
echo \
```

The backslash (`\`) is an escape character in the shell. It is used to:

- **Escape Special Characters**: When used before a special character (such as spaces, quotes, etc.), it prevents the shell from interpreting them in a special way. 
- **Line Continuation**: It is often used to indicate that the command continues on the next line.

In this case, when you run `echo \` and press Enter, the shell will likely wait for further input (because the backslash is expecting more input on the next line). This happens because the backslash is escaping the newline, and the shell expects the continuation of the command.

If you press `Enter` without providing more input, it will just return a blank line.

---

## 2. Creating a Bash Shell Alias `PrintPath`

You can create a Bash shell alias to run the `echo $PATH` command more easily. To create an alias named `PrintPath` for the command `echo $PATH`, you can add the following line to your `~/.bashrc` file (or `~/.bash_profile` for macOS):

```bash
alias PrintPath='echo $PATH'
```

### Steps to Create the Alias:

1. Open the terminal.
2. Edit the `~/.bashrc` file (or `~/.bash_profile` for macOS):
   ```bash
   nano ~/.bashrc
   ```
   Or, for macOS:
   ```bash
   nano ~/.bash_profile
   ```

3. Add the following line at the end of the file:
   ```bash
   alias PrintPath='echo $PATH'
   ```

4. Save the file and exit the editor (in `nano`, press `Ctrl + X`, then press `Y`, and hit Enter).

5. Reload the Bash configuration to apply the alias:
   ```bash
   source ~/.bashrc
   ```

### Using the Alias:

Once the alias is set up, you can use the `PrintPath` command in the terminal to display your system's `PATH` environment variable:

```bash
PrintPath
```

This will output the value of the `PATH` variable, which contains directories where executable programs are located.

---
