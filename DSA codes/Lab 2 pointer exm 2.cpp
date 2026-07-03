#include <iostream>
using namespace std;

int main() {
    int x = 42;

    int* p = &x;     // p points to x
    int** pp = &p;   // pp points to p

    cout << "Value of x: " << x << endl;
    cout << "Address of x (&x): " << &x << endl;

    cout << "Value stored in p (address of x): " << p << endl;
    cout << "Value at address p (*p): " << *p << endl;

    cout << "Value stored in pp (address of p): " << pp << endl;
    cout << "Value at address pp (*pp i.e. p): " << *pp << endl;
    cout << "Value at the address stored in *pp (**pp i.e. x): " << **pp << endl;

    return 0;
}