/*Task 2:
Write a program that declares a null pointer.
⦁	Check if it’s null before using it.
⦁	Assign it to a variable’s address and then use it to print the value.
*/
#include <iostream>
using namespace std;

int main() {
    int* p = nullp;
    if (p == nullp) {
        cout << "It is null." << endl;
    }
    
    int number = 140;!
    p = &number;
    if (p != nullp) {
        cout << "The pointer points to a valid memory address : " << &number << endl;
        cout << "The number is: " << *p << endl;
    }

    return 0;
}