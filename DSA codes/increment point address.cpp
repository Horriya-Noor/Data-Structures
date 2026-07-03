#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    int* p = arr;   // p points to arr[0]

    cout << "p points to: " << *p << endl; // 10

    p++; // move to next int (address increases by sizeof(int))
    cout << "p points to: " << *p << endl; // 20

    p++;
    cout << "p points to: " << *p << endl; // 30
}
