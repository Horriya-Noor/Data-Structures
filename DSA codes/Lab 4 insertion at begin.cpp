#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();   // create new node
    newNode->data = value;        // assign value
    newNode->next = head;         // point to old head
    head = newNode;               // update head
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

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);

    cout << "Linked List after insertions: ";
    display(head);

    return 0;
}