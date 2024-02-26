#include "msgs.h"
#include "shell.h"
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_HISTORY_SIZE 10
#define MAX_COMMAND_LENGTH 1024
typedef struct Command {
  int number; // store the value of the number in the history list
  char command[MAX_COMMAND_LENGTH]; // command variable
} Command;

Command history[MAX_HISTORY_SIZE];
int count = 0; // initialize the count of history functions to 0

void add_to_history(const char *command) {
  Command new_command;
  new_command.number = count;
  strncpy(new_command.command, command, 1023);
  new_command.command[sizeof(new_command.command) - 1] = '\0';
  if (count < MAX_HISTORY_SIZE) {
    history[count++] = new_command;
  }

  else {
    for (int i = 1; i < MAX_HISTORY_SIZE; i++) {
      history[i - 1] = history[i];
    }
    history[MAX_HISTORY_SIZE - 1] = new_command;
    new_command.number = count++;
  }
}

// function to untokenize commands
void combineStrings(const char **args, int count, char *combined) {
  // Initialize combined string
  combined[0] = '\0';

  // Concatenate each argument to the combined string
  for (int i = 0; i < count; i++) {
    strcat(combined, args[i]);
    if (i < count - 1) {
      strcat(combined, " "); // Add a space between arguments
    }
  }
}

void show_history() { // main show history function
  int i;
  for (i = 9; i >= 0; i--) {
    char number_str[20];
    if (history[i].number == 0) {
      continue;
    } else {
      snprintf(number_str, sizeof(number_str), "%d", history[i].number);
      yinka_print(number_str);
      yinka_print(" ");
      yinka_print(history[i].command);
      yinka_print("\n");
    }
  }
}

void runNthCommand(int n) {
  if (n >= count - 10 && n < count) {
    char args_str[20]; // Allocate memory for args_str
    snprintf(args_str, sizeof(args_str), "%d", n); // Convert n to string
    system(history[n - 1].command);
    // execute_fg(history[n].command, &args_str);
  } else {
    printf("Invalid command number.\n");
  }
}

void runLastCommand() {
  if (count == 0) {
    printf("history: no command entered\n");
    return;
  }
  printf("%s", history[count - 1].command);
  system(history[count - 1].command);
}
