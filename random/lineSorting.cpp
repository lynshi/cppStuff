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
    char buffer[10];
    int tempInt;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            sprintf(buffer, "%d", j);
            fullString += tempString;
        }
        writeToFile(fullString);
    }
}

void writeToFile(string writeThis){
    cout << writeThis << endl;
    return;
    vector<string> fileLines;
    string temp;

    ofstream outFile;
    ifstream inFile;

    inFile.open("testOut.txt");

    while(getline(inFile,temp)){
        fileLines.push_back(temp);
    }

    inFile.close();


    for(int i = 0; i < fileLines.size(); i++){
        for(int j = 0; j < fileLines.at(i).length(); j++){
            if(char(fileLines.at(i).at(j)) < char()){

            }
        }
    }
}
