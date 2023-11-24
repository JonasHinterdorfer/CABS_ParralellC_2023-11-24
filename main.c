#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid_ls, pid_df, pid_ps, pid_pwd;

    char* argsLS[] = {"ls", NULL};
    char* argsDF[] = {"df", NULL};
    char* argsPS[] = {"ps", NULL};
    char* argsPWD[] = {"pwd", NULL};

    if ((pid_ls = fork()) == 0) {
        execvp(argsLS[0], argsLS);
    }

    if ((pid_df = fork()) == 0) {
        execvp(argsDF[0], argsDF);
    }

    if ((pid_ps = fork()) == 0) {
        execvp(argsPS[0], argsPS);
    }

    if ((pid_pwd = fork()) == 0) {
        execvp(argsPWD[0], argsPWD);
    }

    waitpid(pid_ls, NULL, 0);
    waitpid(pid_df, NULL, 0);
    waitpid(pid_ps, NULL, 0);
    waitpid(pid_pwd, NULL, 0);

    printf("All processes are done.\n");

    return 0;
}
