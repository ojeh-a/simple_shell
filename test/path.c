#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(void) {
    char buffer[BUFFER_SIZE];
    char *command;
    char *path = NULL;
    size_t len = 0;

    while (1) {
        printf("$ "); // Display a prompt
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("\n"); // Handle Ctrl+D (EOF)
            break;
        }

        // Remove the newline character
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        command = strtok(buffer, " "); // Split the input into tokens
        if (command == NULL) {
            continue; // Empty command, display the prompt again
        }

        // Check if the command exists in the PATH
        char *token = strtok(getenv("PATH"), ":");
        while (token != NULL) {
            path = (char *)malloc(strlen(token) + strlen(command) + 2);
            if (path == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            strcpy(path, token);
            strcat(path, "/");
            strcat(path, command);

            if (access(path, X_OK) == 0) {
                pid_t child_pid = fork();
                if (child_pid == 0) {
                    // Child process
                    execvp(path, &command);
                    perror("execvp");
                    exit(EXIT_FAILURE);
                } else if (child_pid > 0) {
                    // Parent process
                    wait(NULL);
                    free(path);
                    break; // Command found and executed, exit loop
                } else {
                    perror("fork");
                }
            } else {
                free(path);
                path = NULL;
                token = strtok(NULL, ":");
            }
        }

        if (path == NULL) {
            printf("Command not found: %s\n", command);
        }
    }

    return 0;
}

