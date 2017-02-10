#include<iostream>

void add_one(int& n) { n += 1; }
void add_one(int* const n) { *n += 1; }

int main(){
	int i = 5;
	int &refi = i;
	char j = 'j';
	char &refj = j;

	std::cout << refi << refj << std::endl;

	add_one(i);
	std::cout << i << std::endl;

	add_one(&i);
	std::cout << i << std::endl;

	//add_one(0); breaks program
	//std::cout << i << std::endl;

	add_one(0);
	std::cout << i << std::endl;
}