#include<iostream>
#include<fstream>

int main(){
	std::ofstream outFile;
	outFile.open("fileIO.txt");
	outFile << "Hello World" << std::endl;
	outFile << "!!!\n";
	outFile.close();

	std::cout << "lolz\a\n";
}