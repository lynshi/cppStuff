#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctime>
#include<stdlib.h>
using namespace std;

int main(){
    vector<string> fileLines;
    string temp;

    ofstream outFile;
    outFile.open("testOut.txt");
    ifstream inFile;

    srand(time(0));

    for(int i = 0; i < 10; i += 2){
        outFile << i;
        for(int i = 0; i < 3; i++){
            outFile << rand() % 10;
        }
        outFile << endl;
    }

    outFile.close();
    inFile.open("testOut.txt");

    while(getline(inFile,temp)){
        fileLines.push_back(temp);
    }

    for(int i = 0; i < fileLines.size(); i++){
        cout << fileLines.at(i) << endl;
    }
}
