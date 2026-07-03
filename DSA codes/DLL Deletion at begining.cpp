#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

// Delete from beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* temp = head;       // first node to be deleted
    head = head->next;       // move head to next node

    if (head != nullptr) {
        head->prev = nullptr; // update new head's prev
    }

    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

// Display list
void display(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert nodes at beginning
    insertAtBeginning(head, 30); 
    insertAtBeginning(head, 20); 
    insertAtBeginning(head, 10); 

    cout << "Original List:" << endl;
    display(head);

    // Delete node at beginning
    deleteAtBeginning(head); // deletes 30

    cout << "After Deletion:" << endl;
    display(head);

    return 0;
}