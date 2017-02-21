#include <iostream>
#include <string>

// Required by fork routine
#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>   // Declaration for exit()
#include <stdio.h>

using namespace std;

int main(){
    for(int i = 0; i < 10; i++){
        pid_t pID = vfork();
        usleep(1000); // Forces numbers to be displayed in order
        if (pID == 0){
            string frame = "123#";
            frame += char(i+48);
            frame += char(i+48);
            execlp("cansend", "cansend", "vcan0", frame.c_str(), (char *) 0);
            cout << "This should never print." << endl;
        }
    }
    for(int i = 0; i < 6; i++){
        pid_t pID = vfork();
        usleep(1000); // Forces numbers to be displayed in order
        if (pID == 0){
            string frame = "123#";
            frame += char(i+65);
            frame += char(i+65);
            execlp("cansend", "cansend", "vcan0", frame.c_str(), (char *) 0);
            cout << "This should never print." << endl;
        }
    }
    cout << "Everything is done" << endl;
}
