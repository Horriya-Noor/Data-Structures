#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
// Insert at beginning (circular list)
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();   // create new node
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;   // points to itself
    } else {
        Node* temp = head;
        // find last node
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;   // last node points to new node
        newNode->next = head;   // new node points to old head
        head = newNode;         // update head
    }
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

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);

    cout << "Circular Linked List after insertions: ";
    display(head);

    return 0;
}