#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
// Insert at end to create initial list
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
// Delete node at specific position using ONLY ONE if
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    // Case: delete first node
    if (position == 1) {
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
        return;
    }
    // Traverse to node at position
    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }
    // Use ONLY ONE if statement to adjust links
    if (temp->prev != nullptr) {  
        temp->prev->next = temp->next ? temp->next : nullptr;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
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

    // Create list: 10 20 30 40
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Original List:" << endl;
    display(head);

    // Delete node at position 3
    deleteAtPosition(head, 3);

    cout << "After Deletion at position 3:" << endl;
    display(head);

    return 0;
}