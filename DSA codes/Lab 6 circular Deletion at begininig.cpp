#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    Node* temp = head;
    while (temp->next != head) {  
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head; 
}

void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }
    //  Only one node
    if (head->next == head) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }

    //  More than one node
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    Node* temp = head;
    head = head->next;     
    last->next = head;     
    cout << "Deleted: " << temp->data << endl;
    delete temp;
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

    cout << "Original Circular List: ";
    display(head);

    deleteAtBeginning(head);

    cout << "After Deletion at Beginning: ";
    display(head);

    return 0;
}