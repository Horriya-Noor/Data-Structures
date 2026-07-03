#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of the stack

class Stack {
private:
    int arr[MAX];  
    int  top;       

public:
    // Constructor
    Stack() {
        top = -1;  // Stack starts empty
    }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // Pop operation: remove the top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
        } else {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    // Peek operation: view the top element without removing it
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

// Main function
int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.display();

    // Pop the top element only once
    s.pop();
    s.display();

    return 0;
}