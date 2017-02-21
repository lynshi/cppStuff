#include <iostream>
#include <string>

// Required by fork routine
#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>   // Declaration for exit()

using namespace std;

int globalVariable = 2;

int main()
{
   string sIdentifier;
   int    iStackVariable = 20;

   cout << "Does this print twice?" << endl;
   // No, so forked programs must start running after vfork()

   pid_t pID = vfork(); // if fork() is used instead
   // child process does not necessarily execute first
   // exit() is needed to terminate vfork() or it will run forever
   if (pID == 0)                // child
   {
      // Code only executed by child process

      sIdentifier = "Child Process: ";
      globalVariable++;
      iStackVariable++;
      // The following is unneded if fork() used
      cout << sIdentifier;
      cout << " Global variable: " << globalVariable;
      cout << " Stack variable: "  << iStackVariable << endl;
      _exit(0);
    }
    else if (pID < 0)            // failed to fork
    {
        cerr << "Failed to fork" << endl;
        exit(1);
        // Throw exception
    }
    else                                   // parent
    {
      // Code only executed by parent process

      sIdentifier = "Parent Process:";
    }

    // Code executed by both parent and child.
    // But not if there is vfork()

    cout << sIdentifier;
    cout << " Global variable: " << globalVariable;
    cout << " Stack variable: "  << iStackVariable << endl;
}
