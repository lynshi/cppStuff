#include<iostream>
#include <stdlib.h>   // Declaration for exit()
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main(){
    while(1){
        //usleep(1000000);
        pid_t pID = vfork();
        if(pID == 0)
            execlp("cansend", "cansend", "vcan0", "000#AA", (char *) 0);
    }
}
