#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
// Insert at end (to create list)
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
// Delete node at the end
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    // Case: only one node
    if (head->next == nullptr) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }
    // Traverse to last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // Adjust previous node's next
    temp->prev->next = nullptr;
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

    // Delete node at end
    deleteAtEnd(head);

    cout << "After Deletion at end:" << endl;
    display(head);

    return 0;
}