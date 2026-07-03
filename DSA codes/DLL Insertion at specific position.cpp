#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // Case 1: Insert at beginning (position 1)
    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    // Traverse to the (position-1)-th node
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // If position is invalid (greater than list length + 1)
    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    // Insert newNode after temp
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Function to display list from start to end
void display(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = nullptr;

    // Insert some nodes
    insertAtPosition(head, 10, 1);  
    insertAtPosition(head, 20, 2);  
    insertAtPosition(head, 30, 3);  
    insertAtPosition(head, 40, 4);  
    insertAtPosition(head, 25, 3);
    display(head);

    return 0;
}