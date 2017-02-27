#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <iostream>

int main(){
    long long addToThis=0;

    int pipefd[2];
    int buf;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pID = fork();

    if (pID == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pID == 0) {
        close(pipefd[1]);

        for(; addToThis < 100; addToThis++)
            ;

        while (read(pipefd[0], &buf, sizeof(addToThis)) > 0)
            addToThis += buf;

        printf("%llu\n", addToThis);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);

    } else {
        close(pipefd[0]);

        for(; addToThis < 100; addToThis++)
            ;

        write(pipefd[1], &addToThis, sizeof(addToThis));
        close(pipefd[1]);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}
