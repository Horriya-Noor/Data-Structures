/*
Task 3:
Write a C++ program that dynamically allocates memory for a 2D array of integers (matrix) using a pointer-to-pointer.
•	The user enters the number of rows and columns.
•	The program should take input for all elements, display them in matrix form, and finally free the allocated memory.
*/

#include <iostream>

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    int** matrix = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    std::cout << "\nEnter the matrix elements:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element at [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "\n--- The Matrix ---" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr; 

    std::cout << "\nMemory has been successfully deallocated." << std::endl;

    return 0;
}