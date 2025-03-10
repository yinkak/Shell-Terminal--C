#include "shell.h"
#include "msgs.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void display_prompt() {
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    yinka_print(cwd);  // Print the cwd
    yinka_print("$ "); //$ at the end of the prompt
  } else {
    char *msg = FORMAT_MSG("cwd", GETCWD_ERROR_MSG);
    write(STDERR_FILENO, msg, strlen(msg));
    exit(EXIT_FAILURE);
  }
}
