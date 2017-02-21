#include <unistd.h>
int main()
{
    while(1){ // looks like program terminates right after execlp without fork
        execlp("cansend", "cansend", "vcan0", "123#R", (char *) 0);
    }
}
