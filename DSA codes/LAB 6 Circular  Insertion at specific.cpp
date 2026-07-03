#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void insertAtPosition(Node*& head, int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;

    // Case 1: Empty list
    if (head == nullptr) {
        if (pos != 1) {
            cout << "Invalid position! List empty." << endl;
            delete newNode;
            return;
        }
        head = newNode;
        newNode->next = head; // circular link
        return;
    }
    // Case 2: Insert at beginning (pos == 1)
    if (pos == 1) {
        Node* temp = head;
        while (temp->next != head) { // find last node
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    // Case 3: Insert at specific position
    Node* temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }
    // If position is beyond length+1
    if (count < pos - 1) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
// Display circular list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
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