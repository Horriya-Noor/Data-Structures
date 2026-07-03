#include <iostream>   //Task 2
using namespace std;

int main() {
    char* ch = new char;
    cout << "Enter a character: ";
    cin >> *ch;
    cout << "You entered: " << *ch << endl;
    delete ch;
    ch = nullptr;
    return 0;
}

