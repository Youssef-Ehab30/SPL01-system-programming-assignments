# C Shell Implementations – SPL01 System Programming Assignments

This repository contains a series of custom shell programs written in C for the **System Programming Lab (SPL01)**. Each shell introduces new features, starting from basic command parsing and built-in command handling, all the way to variable expansion and I/O redirection.

---

## 🔧 Compilation

Each shell is implemented in its own directory. To compile any shell:

```bash
gcc -o <executableName> <sourceFile>.c
```

Example for Femto Shell:

```bash
gcc -o myFemtoShell FemtoShell.c
```

---

## 🧩 Shell Descriptions and Examples

### 🟢 Femto Shell

A minimal shell that supports only two built-in commands:

- `echo`: Echoes user input.
- `exit`: Terminates the shell with a goodbye message.
- Any other command prints `Invalid command`.

#### Example Output

```bash
$ ./myFemtoShell
Femto shell prompt > echo Hello my shell
Hello my shell
Femto shell prompt > ls
Invalid command
Femto shell prompt > exit
Good Bye :)
$
```

---

### 🔵 Pico Shell

An extended version of Femto Shell with:

- Built-in commands: `echo`, `pwd`, `cd`, `exit`.
- Argument parsing with space as delimiter.
- Execution of external commands via `fork` + `execvp`.
- Dynamic memory allocation to handle variable-length input and arguments.

#### Example Output

```bash
$ ./myPicoShell
Pico shell prompt > echo Hello my shell
Hello my shell
Pico shell prompt > cd /tmp
Pico shell prompt > pwd
/tmp
Pico shell prompt > ls
file.txt file.c
Pico shell prompt > exit
Good Bye :)
$
```

---

### 🟣 Nano Shell

Extends Pico Shell with **local and environment variable support**:

- Assignment via `var=value` syntax.
- Invalid formats are rejected (e.g., `x = 5` or `x=5 echo test`).
- Local variables stored internally.
- `export` command adds local variables to the environment.
- `$var` substitution in command arguments.
- Inherited environment in child processes includes only exported variables.

#### Example Output

```bash
Nano Shell Prompt > x = 5
Invalid command
Nano Shell Prompt > x=5 echo hello
Invalid command
Nano Shell Prompt > x=5
Nano Shell Prompt > echo $x
5
Nano Shell Prompt > folder=home
Nano Shell Prompt > ls /$folder
# lists contents of /home
Nano Shell Prompt > export x
Nano Shell Prompt > printenv | grep x
x=5
```

---

### 🔴 Micro Shell

The most advanced shell in the series, adding **I/O redirection**:

- Supports `<`, `>`, and `2>` in any combination:
  - `<` for input redirection.
  - `>` for standard output redirection.
  - `2>` for standard error redirection.
- Proper error handling if redirection files cannot be opened.
- Command execution is skipped if redirection setup fails.

#### Example Output

```bash
Micro Shell Prompt > echo Hello > out.txt
Micro Shell Prompt > cat < out.txt
Hello
Micro Shell Prompt > ls no_such_file 2> err.txt
Micro Shell Prompt > cat err.txt
ls: cannot access 'no_such_file': No such file or directory
```


## 🧠 Educational Focus

This project demonstrates:

- Low-level Linux system call usage (`fork`, `execvp`, `dup2`, `open`, etc.).
- Manual command parsing and dynamic memory management.
- Custom variable management and I/O redirection handling.
- Best practices in error handling and modular feature design.

---
