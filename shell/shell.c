#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function prototypes
int is_executable(const char *path);
char *find_in_path(const char *command);
void fork_and_exec_cmd(const char *full_path, char *args[]);
void handle_builtin_commands(char *command);
void execute_command(const char *command);
void clean_input(char *input, int buffer_size);

int main()
{
    char input[100];
    while (1)
    {
        printf("$ ");
        fflush(stdout);

        clean_input(input, sizeof(input));

        // Handle exit command
        if (strcmp(input, "exit 0") == 0)
        {
            exit(0);
        }

        // Parse and execute the input command
        if (strncmp(input, "echo ", 5) == 0 || strncmp(input, "type ", 5) == 0)
        {
            handle_builtin_commands(input);
        }
        else
        {
            execute_command(input);
        }
    }

    return 0;
}

// Check if a command is executable
int is_executable(const char *path)
{
    return access(path, X_OK) == 0;
}

// Find command in PATH
char *find_in_path(const char *command)
{
    char *path_env = getenv("PATH");
    if (path_env == NULL)
        return NULL;

    char *path_copy = strdup(path_env);
    char *dir = strtok(path_copy, ":");
    static char full_path[1024];

    while (dir != NULL)
    {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
        if (is_executable(full_path))
        {
            free(path_copy);
            return full_path;
        }
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

// Fork and execute a command
void fork_and_exec_cmd(const char *full_path, char *args[])
{
    pid_t pid = fork();
    if (pid == 0)
    {
        execv(full_path, args);
        perror("execv");
        exit(1);
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
    }
    else
    {
        perror("fork");
    }
}

// Clean input from newline character
void clean_input(char *input, int buffer_size)
{
    if (fgets(input, buffer_size, stdin) != NULL)
    {
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n')
        {
            input[len - 1] = '\0';
        }
    }
}

// Handle built-in commands (echo and type)
void handle_builtin_commands(char *command)
{
    if (strncmp(command, "echo ", 5) == 0)
    {
        printf("%s\n", command + 5);
    }
    else if (strncmp(command, "type ", 5) == 0)
    {
        char *cmd = command + 5;

        if (strcmp(cmd, "echo") == 0 || strcmp(cmd, "exit") == 0 || strcmp(cmd, "type") == 0)
        {
            printf("%s is a shell builtin\n", cmd);
        }
        else
        {
            char *path = find_in_path(cmd);
            if (path)
            {
                printf("%s is %s\n", cmd, path);
            }
            else
            {
                printf("%s: not found\n", cmd);
            }
        }
    }
}

// Execute an external command
void execute_command(const char *command)
{
    char *args[20];
    int argc = 0;

    // Tokenize command into arguments
    char *token = strtok((char *)command, " ");
    while (token != NULL && argc < 19)
    {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    char *cmd_path = find_in_path(args[0]);
    if (cmd_path)
    {
        fork_and_exec_cmd(cmd_path, args);
    }
    else
    {
        printf("%s: command not found\n", args[0]);
    }
}
