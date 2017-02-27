#include<iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
using namespace std;

int main(){
    int addToThis=0;

    /* For comparison
    for(; addToThis < 200; addToThis++)
        ;
    cout << "Sum: " << addToThis << endl;
    */

    // Not actually faster in this case, probably because of low final sum
    // Can't add to much higher because WEXITSTATUS only returns the 8 least
    //      significant bits
    int wstatus;

    pid_t pID1 = fork();

    if(pID1 == 0){
        for(int i = 0; i < 100; i++){
            addToThis++;
        }
        cout << "Forked sum: " << addToThis << endl;
        _exit(addToThis);
    }
    else{
        for(int i = 0; i < 100; i++)
            addToThis++;
        cout << "Main sum: " << addToThis << endl;

        waitpid(pID1,&wstatus,0);
        if(WIFEXITED(wstatus))
            addToThis += WEXITSTATUS(wstatus);

        cout << "Total sum: " << addToThis << endl;
    }
}
