## Simple Shell

## Overview

This project is a Simple Shell implementation written in C, designed as part of CMPT 201 coursework. The shell provides basic functionality for executing commands, supports internal commands, handles background processes, manages a command history, and gracefully deals with signals like CTRL-C.

## Code Structure

```bash
  a8
  |-- CMakeLists.txt
  |-- include
  |   \-- *.h
  |-- gtest
  |   \-- (test source)
  \-- src
      \-- *.c
```

# Features

- External Command Execution
  - Executes standard Linux commands.
  - Supports both:
    - Foreground execution (waits for completion).
    - Background execution (with & at the end).
- Internal Commands
  The shell supports the following built-in commands:

## Internal Commands

| Command   | Description                                                            |
| --------- | ---------------------------------------------------------------------- |
| `exit`    | Exits the shell (**no arguments allowed**).                            |
| `pwd`     | Prints the current working directory.                                  |
| `cd`      | Changes directories with support for `~`, `-`, and the home directory. |
| `help`    | Provides information about internal commands.                          |
| `history` | Displays the last 10 commands executed.                                |

## History Feature

| Feature          | Description                                                              |
| ---------------- | ------------------------------------------------------------------------ |
| Command Tracking | Keeps track of the **last 10 commands** (including background commands). |
| `!!`             | Repeats the **last command**.                                            |
| `!n`             | Repeats the command with **number _n_**.                                 |

## Signal Handling

| Signal            | Behavior                                                 |
| ----------------- | -------------------------------------------------------- |
| `CTRL-C (SIGINT)` | Prevents the shell from terminating and displays \*\*hel |

## Error Handling

Standard error messages are handled using provided macros (msgs.h) to ensure proper output. Errors such as:

- Invalid command
- Forking issues
- Directory errors
- Invalid history requests ...are all covered.

## Example Usage

```bash
/home/user$ ls -la
/home/user$ cd ~/projects
/home/user$ history
/home/user$ !!     # Repeats the last command
/home/user$ !5     # Repeats the command with history number 5
/home/user$ cat file.txt &
```

## Acknowledgment

Created by Mohamed Hefeeda, modified by Brian Fraser, Keval Vora, Tianzheng Wang, and Steve Ko.
