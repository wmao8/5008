#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXARGS 5
#define MAXLINE 8192

char *commands[4] = {"cd", "help", "exit", "gameCommand"};

char path[MAXLINE] = "/";

typedef void *(*CommandFuncPtr)(void *arg);

void *cd(void *input) {
    char **argv = (char **) input;
    // cd or cd ~
    if (argv[1] == NULL || strcmp(argv[1], "~") == 0) {
        char *homeDir = getenv(("HOME"));
        if (homeDir == NULL) {
            fprintf(stderr, "cd: Failed to find the home directory");
            return NULL;
        }
        if (chdir(homeDir) != 0) {
            perror("cd: Failed to go to home directory");
            return NULL;
        }
        // cd ..
    } else {
        if (chdir(argv[1]) != 0) {
            perror("cd: Failed to change directory");
            return NULL;
        }
    }
    return NULL;
}


void *help(void *input) {
    printf("HELP SUMMARY: list of commands\n");
    printf("cd and cd ~: take back to root of directory \n");
    printf("cd _folder_: enter the folder \n");
    printf("cd ..: go back up on level \n");
    printf("help: list of commands and their functions\n");
    printf("gameCommand: This is a game command based on rubrics\n");
    printf("exit: exit the program\n");
    return NULL;
}

void *gameCommand(void *input) {
    printf("This is a game command\n");
    return NULL;
}

void *exit_shell(void *input) {
    exit(1);
}

//  void *(*command_functions[4])(void *) = {cd, help, exit_shell, gameCommand};
CommandFuncPtr command_functions[4] = {cd, help, exit_shell, gameCommand};

/***
 **  Wrapper of fork(). Checks for fork errors, quits on error. 
 **/
pid_t Fork(void) {
    pid_t pid;
    if ((pid = fork()) < 0) {
        fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
        exit(0);
    }
    return pid;
}

/***
 **  Wrapper of fgets. Checks and quits on Unix error. 
 **/
char *Fgets(char *ptr, int n, FILE *stream) {
    char *rptr;
    if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
        fprintf(stderr, "%s\n", "fgets error");
        exit(0);
    }
    return rptr;
}

// Is the command one built into the shell?
// That is, that the *shell* has implemented?
// If so, execute it here

int builtin_command(char **argv) {
    if (strcmp(argv[0], "exit") == 0) {
        exit_shell(argv);
        return 1;
    }
    for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); ++i) {
        if ((strcmp(commands[i], argv[0]) == 0)) {
            command_functions[i]((void *) argv);
            return 1;
        }
    }
    printf("Command not found in the shell\n");

    return 0;
}


void eval(char *cmdline) {
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Holds modified command line */
    pid_t pid;           /* Process id */

    snprintf(buf, sizeof(buf), "%s", cmdline);  //  strcpy(buf, cmdline);
    // Split buf into args
    char *token;
    char *strtokPtr;
    token = strtok_r(buf, " \t\n", &strtokPtr);
    //    printf("Debug 1 %s", token);//
    int argInt = 0;
    while (token != NULL && argInt < MAXARGS - 1) {
        argv[argInt++] = token;
        //        printf("Debug: Token[%d]: '%s\n'", argInt - 1, token);
        token = strtok_r(NULL, " \t\n", &strtokPtr);
    }
    argv[argInt] = NULL;


    if (argv[0] == NULL) {
        //        printf("Debug: No command entererd. \n ");
        return; /* Ignore empty lines */
    }
    if (!builtin_command(argv)) {
        printf("Executing external cmd\n");

        //  new process
        pid = Fork();
        // Check that the command/program exists
        // in Unix (ie /bin/) OR (see below)
        //  Run the program/command (execve...)--
        //  what is the result of exec if the command is bogus?
        if (pid == 0) {
            // see run_ls.c for an example
            int res = execvp(argv[0], argv);
            if (res < 0) {
                printf("Command not found in this shell\n");
                exit(1);
            }
        } else {
            int progress;
            if (waitpid(pid, &progress, 0) < 0) {
                perror("waitpid error");
            }
        }
    } else {
        // What do we do if it *IS* a command built into the shell?
        //        printf(("Debug: executed built-in command.\n"));
    }
}

int main() {
    char cmdline[MAXLINE]; /* command line buffer */
    while (1) {
        // Print command prompt
        printf("> Enter your command:");
        // Read input from user
        Fgets(cmdline, MAXLINE, stdin);
        // If we get the eof, quit the program/shell
        if (feof(stdin))
            exit(0);
        // Otherwise, evaluate the input and execute.
        eval(cmdline);
    }
}
