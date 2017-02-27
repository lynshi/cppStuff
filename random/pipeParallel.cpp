#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(){
    long long addToThis=0;

    /*// For comparison
    for(; addToThis < 200000000; addToThis++)
        ;
    printf("Sum: %llu\n", addToThis);

    return 0;
    */

    int pipefd[2];
    long long buf;

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

        for(; addToThis < 100000000; addToThis++)
            ;

        while (read(pipefd[0], &buf, sizeof(buf)) > 0)
            addToThis += buf;

        printf("%llu\n", addToThis);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);

    } else {
        close(pipefd[0]);

        for(; addToThis < 100000000; addToThis++)
            ;

        write(pipefd[1], &addToThis, sizeof(addToThis));
        close(pipefd[1]);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}
