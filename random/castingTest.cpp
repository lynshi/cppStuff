#include<iostream>
#include<string>

int main(){
    int x = 53;
    char xChar = x;
    std::cout << "xChar: " << xChar << std::endl;
    return 0;
    std::string test = "123#";
    test += char(x+48);
    std::cout << x << std::endl;
    std::cout << (int) x << std::endl;
    std::cout << test.c_str() << std::endl;
}
