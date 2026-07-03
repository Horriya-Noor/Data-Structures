#include <iostream>   //Task 1
#include <string>
using namespace std;


struct Product {
    string name;
    int code;
    float price;
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product* products = new Product[n];

    cout << "\nEnter product details:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        cout << "Enter name: ";
        cin >> products[i].name;
        cout << "Enter code: ";
        cin >> products[i].code;
        cout << "Enter price: ";
        cin >> products[i].price;
    }

    cout << "\n--- Product List ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Product " << i + 1 << ": "
             << "Name = " << products[i].name
             << ", Code = " << products[i].code
             << ", Price = " << products[i].price << endl;
    }

    delete[] products;
    products = nullptr; 

    return 0;
}

