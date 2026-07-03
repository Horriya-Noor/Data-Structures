#include<iostream>
	using namespace std;
	 int main( )
	 {
	 	
	 int arr[3] = {10, 20, 30};

    int* p = &arr[2];   

    cout << "Pointer initially points to: " << *p << endl; 

    p--;   
    cout << "After p--, pointer points to: " << *p << endl; // 20
    p--;   
    cout << "After another p--, pointer points to: " << *p << endl; 
return 0; }

