#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void writeToFile(string);

int main(){
    ofstream outFile;
    outFile.open("testOut.txt");
    ifstream inFile;

    srand(time(0));

    for(int i = 0; i < 10; i += 2){
        outFile << i;
        for(int j = 0; j < 3; j++){
            outFile << rand() % 10;
        }
        outFile << endl;
    }

    outFile.close();
    string fullString="";
    int tempInt;

    for(int i = 1; i < 10; i += 2){
        for(int j = 0; j < 3; j++){
            tempInt = rand() % 10;
            fullString += char(tempInt+48);
        }
        writeToFile(fullString);
        fullString = "";
    }
}

void writeToFile(string writeThis){
    //cout << writeThis << endl;
    vector<string> fileLines;
    string temp;

    ofstream outFile;
    ifstream inFile;

    inFile.open("testOut.txt");

    while(getline(inFile,temp)){
        fileLines.push_back(temp);
    }

    inFile.close();
    outFile.open("testOut.txt");

    bool orderFlag;

    for(int i = 0; i < fileLines.size(); i++){
        orderFlag = 0;
        for(int j = 0; j < writeThis.length(); j++){
            //cout << fileLines.at(i).at(j) << " " << writeThis.at(j) << endl;
            if(fileLines.at(i).at(j) < writeThis.at(j)){
                outFile << fileLines.at(i) << endl;
                orderFlag = 1;
                break;
            }
            else if(fileLines.at(i).at(j) > writeThis.at(j)){
                break;
            }
        }
        if(!orderFlag){
            outFile << writeThis << endl;
            for(; i< fileLines.size(); i++){
                outFile << fileLines.at(i) << endl;
            }
        }
    }

    if(orderFlag){
        outFile << writeThis << endl;
    }

    outFile.close();
}
