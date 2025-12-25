#include <iostream>
using namespace std;
int main(){
	int size;
	cout<<"Enter the size of array:"<<endl;
	cin>>size;
	
	int *arr = new int[size];
	cout<<"Enter the elements you want to print :"<< endl;
		for(int i =0; i < size; i++ ){
			cin>> *(arr +i );
		
	}
	cout<< "The numbers you have stored:"<< endl;
	for (int i = 0; i < size ; i++){
	 cout<< arr[i] << " ";
}
	delete [] arr ;
	return 0;
	 
}