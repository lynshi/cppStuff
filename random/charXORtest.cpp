#include<iostream>
#include<string>
using namespace std;

int main(){
    string thisLine = "145.85,215738.000,4217.6261,N,08342.7381,W,1,03,4.89,184.0,M,-34.0,M,,*56";
    
    int astPos;
    if((astPos = thisLine.find("*")) == string::npos){
        // GPS communication was not properly terminated, bad data
        return 1;
    }

    int firstCommaPos = thisLine.find(",");

    // Calculating checksum from data, GPGGA not included in data file
    string gpgga = "GPGGA";
    char calcChecksum = gpgga.at(0);
    for(int i = 1; i < gpgga.length(); i++){
        calcChecksum = calcChecksum ^ gpgga.at(i);
    }

    for(int i = firstCommaPos; i < astPos; i++){
        calcChecksum = calcChecksum ^ thisLine.at(i);
    }

    // Convert given checksum to character equivalent
    // Char -> Int (hex) -> Int (dec, ASCII) -> Char
    int msb = int(thisLine.at(astPos+1)) - 48;
    int lsb = int(thisLine.at(astPos+2)) - 48;
    int checkSumNum = msb*16 + lsb;
    char checksum = char(checkSumNum);
    
    cout << "Checksum: " << checksum << "\nCalculated checksum: " << calcChecksum << endl;

    if(calcChecksum != checksum)
        cout << "Error checksums don't match." << endl;

    cout << "Checksum good" << endl;
}
