#include<iostream>

int main(){
	int i  = 42;
	int *ptrToI = &i; //points to i
	int *const constPtrToI = &i; // points to i, cannot be changed to point to anything else
	int &refToI = i; //binds refToI to i

	std::cout << "i = " << i << "\tAddress of i = " << &i << std::endl;
	std::cout << "*ptrToI (really i) = " << *ptrToI << "\tAddress of ptrToI = " << &ptrToI << "\tContents of ptrToI = " << ptrToI << std::endl;
	std::cout << "refToI (really i) = " << refToI << "\t&refToNum = " << &refToI << std::endl;
	std::cout << "*constPtrToI = " << *constPtrToI << "\t&constPtrToI = " << &constPtrToI << "\tContents of constPtrToI = " << constPtrToI << std::endl;

	int *&refToPtr = ptrToI;

	std::cout << "refToPtr = " << refToPtr << "\t*refToPtr = " << *refToPtr << std::endl;
}