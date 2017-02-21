#include<iostream>
#include <stdlib.h>   // Declaration for exit()
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main(){
    execlp("cansend", "cansend", "vcan0", "123#1234", (char *) 0);
}
