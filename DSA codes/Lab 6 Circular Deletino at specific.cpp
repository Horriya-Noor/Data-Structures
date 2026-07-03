#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end (circular)
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head; // circular
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Delete at specific position
void deleteAtPosition(Node*& head, int pos) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    // Case 1: delete head (position 1)
    if (pos == 1) {
        // Only one node
        if (head->next == head) {
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = nullptr;
            return;
        }

        // More than one node
        Node* last = head;
        while (last->next != head) {  // find last node
            last = last->next;
        }

        Node* del = head;
        head = head->next;   
        last->next = head;   
        cout << "Deleted: " << del->data << endl;
        delete del;
        return;
    }

    // delete at other position
    Node* current = head;
    int count = 1;
    while (count < pos - 1 && current->next != head) {
        current = current->next;
        count++;
    }
    // if position is invalid
    if (current->next == head) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* del = current->next;        
    current->next = del->next;       
    cout << "Deleted: " << del->data << endl;
    delete del;
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
    insertAtEnd(head, 50);

    cout << "Original Circular List: ";
    display(head);

    deleteAtPosition(head, 2);

    cout << "After Deletion at Position 2: ";
    display(head);

    deleteAtPosition(head, 1);

    cout << "After Deletion at Position 1: ";
    display(head);

    deleteAtPosition(head, 10); 

    return 0;
}