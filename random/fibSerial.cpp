#include<iostream>
#include<vector>
using namespace std;

int main(){
    unsigned long long times;
    vector<unsigned long long> fibNums;

    cout << "Which element would you like to display? ";
    cin >> times;

    fibNums.push_back(1);
    fibNums.push_back(1);

    for(unsigned long long i = 2; i < times; i++){
        fibNums.push_back(fibNums.at(i-1) + fibNums.at(i-2));
    }
    cout << fibNums[times-1] << endl;
}
