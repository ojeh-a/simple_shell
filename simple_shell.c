#include "shell.h"

#define MAX_COMMAND_LENGTH 100
/**
 * main - simple shell
 *
 * Return: 0
 */
int main() {
    char* command = NULL;
    size_t command_size = 0;
    pid_t pid;

    while (1) {
        printf("#cisfun$ ");
        if (getline(&command, &command_size, stdin) == -1) {
            break;
        }
        
        command[strcspn(command, "\n")] = '\0';
        
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            
            char* tokens[MAX_COMMAND_LENGTH];
            char* token = strtok(command, " ");
            int i = 0;
            while (token != NULL) {
                tokens[i++] = token;
                token = strtok(NULL, " ");
            }
            tokens[i] = NULL;

            if (execv(tokens[0], tokens) == -1) {
                perror("execv");
                exit(EXIT_FAILURE);
            }
        } else {

            if (wait(NULL) == -1) {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }
    
    free(command);
    return 0;
}
