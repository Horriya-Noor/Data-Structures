#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAtEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    if (head->next == NULL) {  // only one node
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {  // move to second last node
        temp = temp->next;
    }

    Node* del = temp->next;
    cout << "Deleted: " << del->data << endl;
    temp->next = NULL;
    delete del;
}

// Function to display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Original List: ";
    display(head);

    deleteAtEnd(head);

    cout << "After Deletion at End: ";
    display(head);

    return 0;
}