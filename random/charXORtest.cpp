#include<iostream>
#include<string>
using namespace std;

int main(){
    string test = "Hello World";
    cout << int(test[0] ^ test[1]) << endl;

    return 0;
}
