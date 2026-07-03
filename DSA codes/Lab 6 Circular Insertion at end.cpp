#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    // Empty list
    if (head == nullptr) {
        head = newNode;
        newNode->next = head; 
        return;
    }
    //  traverse to last node
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head; // maintain circular link
}


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

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Circular Linked List  insertions at end: ";
    display(head);

    return 0;
}