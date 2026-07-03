#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Case 1: If list is empty
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Case 2: Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Link new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}
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
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    display(head);

    return 0;
}