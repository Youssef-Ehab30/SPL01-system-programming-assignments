# Unix Utilities — SPL01 System Programming Assignments  

## Project Folder: `unix-utilities/`  

This repository contains basic implementations of common Unix utilities developed as part of the **System Programming Lab (SPL01)** assignments. Each utility is written in **C**, leveraging low-level system calls such as `open`, `read`, `write`, `close`, `unlink`, and `rename`, without depending on high-level C standard library functions for core functionality.  

---

## Implemented Utilities  

### 1. `pwd` — Print Working Directory  
Prints the absolute path of the current working directory.  

- **System calls used**: `getcwd`  
- **Usage example**:  
  ```bash
  ./pwd
  /home/user/projects/unix-utilities
  ```

### 2. `echo` — Print Text to Standard Output  
Displays the provided arguments on the terminal, separated by spaces.  

- **Usage example**:  
  ```bash
  ./echo Hello Unix World
  Hello Unix World
  ```

### 3. `cp` — Copy Files  
Copies a file from a **source path** to a **destination path**.  

- **System calls used**: `open`, `read`, `write`, `close`  
- **Usage example**:  
  ```bash
  ./cp source.txt /tmp/destination.txt
  ```

### 4. `mv` — Move/Rename Files  
Moves or renames a file to a specified destination. The utility first attempts to use `rename()` for efficiency but falls back to **copying + unlinking** if needed.  

- **System calls used**: `rename`, `open`, `read`, `write`, `close`, `unlink`  
- **Usage example**:  
  ```bash
  ./mv /tmp/file.txt /tmp/renamed.txt
  ./mv /tmp/file.txt /home/reda/file.txt
  ```

---

## Compilation  
Each utility can be compiled using `gcc`.  

```bash
gcc -o pwd pwd.c
gcc -o echo echo.c
gcc -o cp cp.c
gcc -o mv mv.c
```

---

## Running the Utilities  
To run each utility, navigate to the directory containing the compiled executables and use the following commands: 

```bash
./pwd
./echo Hello World
./cp source.txt destination.txt
./mv source.txt destination.txt
```
