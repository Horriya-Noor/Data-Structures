#include<iostream>
using namespace std;
int main( )
{  int arr[5] = {10, 20, 30, 40, 50};

    int* p = arr;  // points to arr[0]

    cout << "p points to: " << *p << endl;       

    cout << "*(p + 1) = " << *(p + 1) << endl;    
    cout << "*(p + 2) = " << *(p + 2) << endl;   
    cout << "*(p + 3) = " << *(p + 3) << endl;    
    cout << "*(p + 4) = " << *(p + 4) << endl;   

   
    int* q = p + 2;   
    cout << "q points to: " << *q << endl;

    return 0;


}