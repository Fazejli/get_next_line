# 📖 Get Next Line — Read a File Line by Line

> Implementing a function that reads any file descriptor one line at a time, managing buffers and persistent state in C.

![Score](https://img.shields.io/badge/Score-100%2F100-brightgreen?style=flat-square)
![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white)
![School](https://img.shields.io/badge/School-42-000000?style=flat-square)

---

## 📌 Overview

`get_next_line` is a 42 project that consists of coding a function which returns the next line from a file descriptor — one call at a time.

The challenge lies in handling a **static buffer** that persists between calls, correctly managing memory, and supporting any `BUFFER_SIZE` value from `1` to `100000+`. The bonus extends this to **multiple file descriptors simultaneously**.

---

## ⚙️ Function Prototype

```c
char *get_next_line(int fd);
```

| Parameter | Description |
|-----------|-------------|
| `fd` | File descriptor to read from (file, stdin, pipe…) |

Returns the next line including `\n`, or `NULL` on EOF or error.

---

## 📂 Files

**Mandatory**

| File | Description |
|------|-------------|
| `get_next_line.c` | Core function — reads and returns the next line |
| `get_next_line_utils.c` | Helper functions used by the main logic |
| `get_next_line.h` | Header file |

**Bonus — Multiple file descriptors**

| File | Description |
|------|-------------|
| `get_next_line_bonus.c` | Handles simultaneous reads on multiple fds |
| `get_next_line_utils_bonus.c` | Helper functions for the bonus |
| `get_next_line_bonus.h` | Header file for bonus |

---

## 🛠️ Usage

```bash
git clone https://github.com/your_login/get_next_line.git
cd get_next_line
```

Add the source files to your project and compile with a buffer size:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c main.c -o gnl
```

Then use it in your code:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## 📁 Project Structure

```
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
└── get_next_line.h
```

---

## 🧠 Key Concepts

- Static variables and persistent state across function calls
- Dynamic memory allocation (`malloc`, `free`)
- Low-level file I/O with `read()`
- Buffer management and partial-read handling
- String manipulation without standard library
- Multi-fd support via indexed static array (bonus)
