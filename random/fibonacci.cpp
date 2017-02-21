#include<iostream>
#include<vector>

int calcFib(int);

std::vector<int> fibNums;

int main(){
    int times;
    std::cout << "How many elements to display? ";
    std::cin >> times;

    for(int i = 0; i < times; i++)
        fibNums.push_back(0);

    calcFib(times);

    for(int i = 0; i < times; i++)
        std::cout << fibNums.at(i) << " ";

    std::cout << std::endl;
}

int calcFib(int elem){
    if(elem == 1 || elem == 2){
        fibNums.at(elem-1) = 1;
        return 1;
    }

    int currentNum = calcFib(elem-1) + calcFib(elem-2);
    fibNums.at(elem-1) = currentNum;
    return currentNum;
}
