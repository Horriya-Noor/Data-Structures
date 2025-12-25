/*
Task 2:
Write a C++ program that dynamically allocates memory for a single character using the new operator.
•	Store a character in the allocated memory.
•	Print the stored character.
•	Finally, deallocate the memory using the delete operator and set the pointer to nullptr.
*/

#include <iostream>

int main() {
	
    char* myCharacter = new char;
    *myCharacter = 'A';
    std::cout << "The stored character is: " << *myCharacter << std::endl;
    delete myCharacter;
    myCharacter = nullptr;

    std::cout << "Memory has been successfully deallocated." << std::endl;

    return 0;
}