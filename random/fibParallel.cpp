#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <iostream>

unsigned long long calcFib(unsigned long long);

unsigned long long times;

int main(){
    //unsigned long long times;

    std::cout << "Which element to display? ";
    //std::cout << "How many elements to display? ";
    std::cin >> times;

    //pid_t temp = fork();
    // Added to check for consistency
    //for(int i = 0; i < 10; i++)
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
        /*
        if(elem == times)
            std::cout << "Elem: " << elem-2 << " This fibNum: " << fibNum << std::endl;
        */
        write(pipefd[1], &fibNum, sizeof(fibNum));
        exit(0);
    }
    else{
        close(pipefd[1]);
        fibNum = calcFib(elem-1);
        /*
        if(elem == times)
            std::cout << "Elem: " << elem-1 << " This fibNum: " << fibNum << std::endl;
        */
        wait(NULL);
        read(pipefd[0], &buf, sizeof(buf));
        fibNum += buf;
        std::cout << "Elem: " << elem << " Value: " << fibNum << std::endl;
        return fibNum;
    }
}
