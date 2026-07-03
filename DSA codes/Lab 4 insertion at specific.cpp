#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtPosition(Node*& head, int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Insert at given position
    Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        delete newNode;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    
}

int main() {
    Node* head = nullptr;

  
    insertAtPosition(head, 10, 1); 
    insertAtPosition(head, 20, 2); 
    insertAtPosition(head, 40, 3); 

    cout << "Original List: ";
    display(head);

    // Insert 30 at position 3
    insertAtPosition(head, 30, 3);

    cout << "After inserting 30 at position 3: ";
    display(head);

    return 0;
}