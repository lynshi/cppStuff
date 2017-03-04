#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

unsigned long long calcFib(unsigned long long);
int findShorter(string&, string&);

unsigned long long times;

int main(){
    //unsigned long long times;

    cout << "Which element to display? ";
    //std::cout << "How many elements to display? ";
    cin >> times;

    //pid_t temp = fork();
    // Added to check for consistency
    //for(int i = 0; i < 10; i++)
    cout << calcFib(times) << endl;
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
        ofstream outFile("fibParallel.txt");
        close(pipefd[1]);
        fibNum = calcFib(elem-1);
        /*
        if(elem == times)
            std::cout << "Elem: " << elem-1 << " This fibNum: " << fibNum << std::endl;
        */
        wait(NULL);
        read(pipefd[0], &buf, sizeof(buf));
        fibNum += buf;
        cout << "Elem: " << elem << " Value: " << fibNum << endl;
        outFile << "Elem: " << elem << " Value: " << fibNum << endl;
        outFile.close();
        return fibNum;
    }
}

int findShorter(string &s1, string &s2){
    if(s1.length() < s2.length())
        return s1.length();
    else
        return s2.length();
}
