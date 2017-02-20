#include<iostream>

int main(){
	double initialX, initialY, finalX, stepSize;

	std::cout << "Enter initialX: ";
	std::cin >> initialX;

	std::cout << "Enter initialY: ";
	std::cin >> initialY;

	std::cout << "Enter finalX: ";
	std::cin >> finalX;

	std::cout << "Enter stepSize: ";
	std::cin >> stepSize;

	std::cout << "(" << initialX << ", " << initialY << ")" << std::endl;
	while(initialX < finalX){
		initialY = initialY + stepSize*(0.03*initialY);
		initialX += stepSize;
		std::cout << "(" << initialX << ", " << initialY << ")" << std::endl;
	}
}