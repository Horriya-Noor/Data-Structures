/*
Task 1:
Write a program to store n products dynamically. Each product has a name, code, and price. Take input, print all products, and free memory.
*/

#include <iostream>
#include <string>

struct Product {
    std::string name;
    int code;
    double price;
};

int main() {
    int n;

    std::cout << "Enter the number of products: ";
    std::cin >> n;

    Product* products = new Product[n];

    for (int i = 0; i < n; ++i) {
        std::cout << "\nEnter details for product " << i + 1 << ":" << std::endl;

        std::cin.ignore(); 
        
        std::cout << "  Name: ";
        std::getline(std::cin, products[i].name);
        
        std::cout << "  Code: ";
        std::cin >> products[i].code;
        
        std::cout << "  Price: ";
        std::cin >> products[i].price;
    }

    std::cout << "\n--- Stored Products ---" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Product " << i + 1 << ":" << std::endl;
        std::cout << "  Name: " << products[i].name << std::endl;
        std::cout << "  Code: " << products[i].code << std::endl;
        std::cout << "  Price: $" << products[i].price << std::endl;
    }

    delete[] products;
    products = nullptr; 

    std::cout << "\nMemory has been successfully freed." << std::endl;

    return 0;
}