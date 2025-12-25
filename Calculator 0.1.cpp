#include <iostream>
using namespace std;

class Calculator {
private:
    // Private constructor
    Calculator() {}

    // Static variable to count operations
    static int operationCount;

public:
    // Sum
    static int sum(int x, int y) {
        operationCount++;
        return x + y;
    }

    // Difference
    static int difference(int x, int y) {
        operationCount++;
        return x - y;
    }

    // Quotient (Division)
    static double quotient(double x, double y) {
        operationCount++;
        if (y == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0; // return 0 when invalid
        }
        return x / y;
    }

    // Remainder
    static int remainder(int x, int y) {
        operationCount++;
        if (y == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0; // return 0 when invalid
        }
        return x % y;
    }

    // Percentage
    static double percentage(double x, double y) {
        operationCount++;
        if (y == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0; // return 0 when invalid
        }
        return (x / y) * 100;
    }

    // Get total number of operations
    static int getOperationCount() {
        return operationCount;
    }
};

// Initialize static variable
int Calculator::operationCount = 0;

int main() {
    float num1, num2;
    int a;
    char continueCalculation = 'y'; // Variable to control the loop

    // The main loop
    while (continueCalculation == 'y' || continueCalculation == 'Y') {
        // List of operations:
        cout << "\nChoose an operation:" << endl;
        cout << "Sum ( + ) = 1" << endl;
        cout << "Difference ( - ) = 2" << endl;
        cout << "Quotient ( / ) = 3" << endl;
        cout << "Remainder = 4" << endl;
        cout << "Percentage ( % ) = 5" << endl;
        cout << "Exit = 0" << endl;

        cout << "\nEnter your choice: ";
        cin >> a;

        // Exit the loop if the user chooses 0
        if (a == 0) {
            break;
        }

        // Prompt the user to enter the two numbers
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

        switch (a) {
            case 1:
                cout << "Sum: " << Calculator::sum(num1, num2) << endl;
                break;
            case 2:
                cout << "Difference: " << Calculator::difference(num1, num2) << endl;
                break;
            case 3:
                cout << "Quotient: " << Calculator::quotient(num1, num2) << endl;
                break;
            case 4:
                cout << "Remainder: " << Calculator::remainder(static_cast<int>(num1), static_cast<int>(num2)) << endl;
                break;
            case 5:
                cout << "Percentage: " << Calculator::percentage(num1, num2) << "%" << endl;
                break;
            default:
                cout << "Error: Invalid choice" << endl;
                break;
        }

        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> continueCalculation;
    }

    cout << "\nTotal Operations Performed: "
         << Calculator::getOperationCount() << endl;

    return 0;
}