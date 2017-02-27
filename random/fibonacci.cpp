#include<iostream>
#include<vector>

unsigned long long calcFib(unsigned long long);

//std::vector<int> fibNums;

int main(){
    unsigned long long times;
    std::cout << "Which element to display? ";
    //std::cout << "How many elements to display? ";
    std::cin >> times;

    /*
    for(int i = 0; i < times; i++)
        fibNums.push_back(0);


    calcFib(times);


    for(int i = 0; i < times; i++)
        std::cout << fibNums.at(i) << " ";
    */

    std::cout << calcFib(times) << std::endl;
}

unsigned long long calcFib(unsigned long long elem){
    if(elem <= 2){
        //fibNums.at(elem-1) = 1;
        return 1;
    }

    return calcFib(elem-1) + calcFib(elem-2);

    int currentNum = calcFib(elem-1) + calcFib(elem-2);
    //fibNums.at(elem-1) = currentNum;
    return currentNum;
}
