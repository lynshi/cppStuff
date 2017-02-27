#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <iostream>

unsigned long long calcFib(unsigned long long);

int main(){
    unsigned long long times;
    std::cout << "Which element to display? ";
    //std::cout << "How many elements to display? ";
    std::cin >> times;

    std::cout << calcFib(times) << std::endl;
}

unsigned long long calcFib(unsigned long long elem){
    unsigned long long fibNum=0, buf;
    int pipefd[2];

    if(elem <= 2){
        return 1;
    }

    pipe(pipefd);
    pid_t pID = fork();

    if(pID == 0){
        close(pipefd[0]);
        fibNum = calcFib(elem-2);
        //std::cout << "Elem: " << elem << " Elem-2: " << fibNum << std::endl;
        write(pipefd[1], &fibNum, sizeof(fibNum));
        exit(0);
    }
    else{
        close(pipefd[1]);
        fibNum = calcFib(elem-1);
        //std::cout << "Elem: " << elem << " Elem-1: " << fibNum << std::endl;
        wait(NULL);
        read(pipefd[0], &buf, sizeof(buf));
        return fibNum += buf;
    }
}
