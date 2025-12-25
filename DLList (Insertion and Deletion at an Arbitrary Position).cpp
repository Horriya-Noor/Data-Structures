#include <iostream>
using namespace std; 

struct Node {
    int data;
    Node* prev; 
    Node* next; 
};


void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* current = head;
    cout << "List (Forward): ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

void insertAtPosition(Node*& head, int data, int position) {
    if (position < 1) {
        cout << "Error: Position must be 1 or greater." << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* current = head;
    int count = 1;

    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Error: Position " << position << " is out of bounds." << endl;
        delete newNode; 
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
}

void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "Error: List is empty. Cannot delete." << endl;
        return;
    }

    if (position < 1) {
        cout << "Error: Position must be 1 or greater." << endl;
        return;
    }

    Node* toDelete = head;
    
    if (position == 1) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete toDelete;
        return;
    }

    int count = 1;
    while (toDelete != nullptr && count < position) {
        toDelete = toDelete->next;
        count++;
    }

    if (toDelete == nullptr) {
        cout << "Error: Position " << position << " is out of bounds. Cannot delete." << endl;
        return;
    }
    if (toDelete->prev != nullptr) {
        toDelete->prev->next = toDelete->next;
    }

    if (toDelete->next != nullptr) {
        toDelete->next->prev = toDelete->prev;
    }

    delete toDelete;
}


int main() {
    Node* head = nullptr;

    cout << "--- Initial Creation and Insertion ---" << endl;
    insertAtPosition(head, 10, 1); 
    insertAtPosition(head, 30, 2); 
    insertAtPosition(head, 20, 2); 
    printList(head); 
    cout << "\n--- Insertion Demonstrations ---" << endl;

    cout << "Inserting 5 at position 1 (new head)..." << endl;
    insertAtPosition(head, 5, 1);
    printList(head); 

    cout << "Inserting 25 at position 4..." << endl;
    insertAtPosition(head, 25, 4);
    printList(head); 

    cout << "Inserting 35 at position 6 (new tail)..." << endl;
    insertAtPosition(head, 35, 6);
    printList(head); 

    cout << "\n--- Deletion Demonstrations ---" << endl;
    cout << "Deleting node at position 1 (5)..." << endl;
    deleteAtPosition(head, 1);
    printList(head); 

    cout << "Deleting node at position 3 (25)..." << endl;
    deleteAtPosition(head, 3);
    printList(head); 

    cout << "Deleting node at position 4 (35)..." << endl;
    deleteAtPosition(head, 4);
    printList(head); 
   
    cout << "Attempting to delete node at position 10 (invalid)..." << endl;
    deleteAtPosition(head, 10);

    cout << "\n--- Cleaning up list memory ---" << endl;
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    printList(head);

    return 0;
}