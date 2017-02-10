#include<iostream>

int reused = 42;

int main(){
	int sum = 0;
	std::cout << reused << std::endl;

	for(int i = 1; i < 10; i++)
		sum += i;

	int reused = 5;

	std::cout << sum + reused << std::endl;
	std::cout << ::reused << std::endl;
}