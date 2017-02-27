#include<iostream>
using namespace std;

int main(){
    unsigned long long times;
    unsigned long long fibNums[3];

    cout << "Which element would you like to display? ";
    cin >> times;

    fibNums[0] = 1;
    fibNums[1] = 1;

    for(unsigned long long i = 2; i < times; i++){
        fibNums[i%3] = fibNums[(i-1) % 3] + fibNums[(i-2) % 3];
    }
    cout << fibNums[(times-1)%3] << endl;
}
