#include <iostream>
using namespace std;

struct Node {
    int data;  
    Node* prev; 
    Node* next; 
};

// Function to print the list from head to tail.
void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is currently empty." << endl;
        return;
    }
    
    Node* current = head;
    cout << "List: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> "; // Separator for linked nodes
        }
        current = current->next;
    }
    cout << endl;
}

//  finding the total number of nodes in the list.
int getLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}


void insertAtPosition(Node*& head, int data, int position) {
    int len = getLength(head);

    if (position < 1 || position > len + 1) {
        cout << "Error: Invalid position (" << position << "). Must be between 1 and " << len + 1 << "." << endl;
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == nullptr) {
        cerr << "Error: Memory allocation failed." << endl;
        exit(1); 
    }
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
    for (int i = 1; i < position - 1; ++i) {
        current = current->next;
    }

    newNode->next = current->next; 
    newNode->prev = current;      
    current->next = newNode;       
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode; 
    }
}

void deleteAtPosition(Node*& head, int position) {
    int len = getLength(head);

// checking for the position
    if (head == nullptr || position < 1 || position > len) {
        cout << "Error: Invalid position (" << position << ") for deletion. List length is " << len << "." << endl;
        return;
    }

    Node* toDelete = head;

// Deletion at the Beginning 
    if (position == 1) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr; 
        }
        free(toDelete); 
        return;
    }


    for (int i = 1; i < position; ++i) {
        toDelete = toDelete->next;
    }

    Node* prevNode = toDelete->prev;
    Node* nextNode = toDelete->next;

    if (prevNode != nullptr) {
        prevNode->next = nextNode;
    }
    
    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    }
    free(toDelete);
}

// Function to clean up memory
void freeList(Node*& head) {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        free(current);
        current = next;
    }
    head = nullptr; 
}

// --- Main Demonstration ---

int main() {
    Node* head = nullptr; 

    // ---  Initial Setup and Demonstration ---
    
    insertAtPosition(head, 10, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 30, 3);
    
    cout << "--- Initial List Setup ---" << endl;
    printList(head);
    cout << "--------------------------" << endl << endl;

    // --- Insertion ---
    
    int insertData, insertPos;
    
    cout << ">>> DEMONSTRATE INSERTION <<<" << endl;
    cout << "Enter data to insert (e.g., 45): ";
    if (!(cin >> insertData)) return 1;
    cout << "Enter 1-based position (e.g., 2 to insert after 10): ";
    if (!(cin >> insertPos)) return 1;

    insertAtPosition(head, insertData, insertPos);

    cout << "\n--- List After Insertion of " << insertData << " at Position " << insertPos << " ---" << endl;
    printList(head);
    cout << "Current Length: " << getLength(head) << endl;
    cout << "--------------------------------------------------------" << endl << endl;

 // --- Demonstrate Deletion ---

    int deletePos;
    
    cout << ">>> DEMONSTRATE DELETION <<<" << endl;
    cout << "Enter 1-based position to delete (1 to " << getLength(head) << "): ";
    if (!(cin >> deletePos)) return 1;

    deleteAtPosition(head, deletePos);

    cout << "\n--- List After Deletion at Position " << deletePos << " ---" << endl;
    printList(head);
    cout << "Current Length: " << getLength(head) << endl;
    cout << "----------------------------------------------" << endl << endl;

// Cleaning up the memory before exiting
    freeList(head);

    return 0;
}