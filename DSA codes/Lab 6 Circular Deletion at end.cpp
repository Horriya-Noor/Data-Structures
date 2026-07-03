#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
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
void deleteAtEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }
    //  Only one node
    if (head->next == head) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = NULL;
        return;
    }
    //More than one node
    Node* temp = head;
    while (temp->next->next != head) {  
        temp = temp->next; // move to second last node
    }

    Node* del = temp->next;  // last node
    cout << "Deleted: " << del->data << endl;
    temp->next = head;       
    delete del;
}
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    Node* head = NULL;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    cout << "Original Circular List: ";
    display(head);
    deleteAtEnd(head);
    cout << "After Deletion at End: ";
    display(head);
    deleteAtEnd(head);
    cout << "After Another Deletion at End: ";
    display(head);
    return 0;
}