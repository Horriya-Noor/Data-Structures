/*
==================================Data structure ====================================================
Assignment 2
Marks 10
CLO 2
Topic: Doubly Linked List - Insertion and Deletion at an Arbitrary Position
Using C++ implement a Node class/struct with data, prev, and next pointers. Implement two functions:
•	insertAtPosition(head, data, position)
•	deleteAtPosition(head, position)
The main function should create a sample doubly linked list, demonstrate both insertion and deletion, 
and print the list after each operation to verify the result.

                			Name:	Horriya Noor
                			Sap Id: 64048
                			Semester: 3rd
                			Department: BSCS 
*/

#include <iostream>
#include <cstdlib> 

using namespace std;

struct Node {
    int data;  
    Node* prev; 
    Node* next; 
};

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is currently empty. 🚫" << endl;
        return;
    }
    
    Node* current = head;
    cout << "\n[ Current List: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << " ]" << endl;
}

int getLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

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

void insertAtPosition(Node*& head, int data, int position) {
    int len = getLength(head);

    if (position < 1 || position > len + 1) {
        cout << "Error: Invalid position. Must be between 1 and " << len + 1 << "." << endl;
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == nullptr) { cerr << "Error: Memory allocation failed." << endl; exit(1); }
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        cout << "✅ Successfully inserted " << data << " at the start." << endl;
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
    cout << "✅ Successfully inserted " << data << " at position " << position << "." << endl;
}


void deleteAtPosition(Node*& head, int position) {
    int len = getLength(head);

    if (head == nullptr) {
        cout << "Error: List is empty. Cannot delete. " << endl;
        return;
    }
    if (position < 1 || position > len) {
        cout << "Error: Invalid position. Must be between 1 and " << len << "." << endl;
        return;
    }

    Node* toDelete = head;

    if (position == 1) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr; 
        }
        cout << "✅ Successfully deleted " << toDelete->data << " from the start." << endl;
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

    cout << "✅ Successfully deleted " << toDelete->data << " from position " << position << "." << endl;

    free(toDelete);
}


void displayMenu() {
    cout << "\n==============================================" << endl;
    cout << "   Doubly Linked List Operations Menu 📋" << endl;
    cout << "==============================================" << endl;
    cout << "1. Insert Node at Arbitrary Position" << endl;
    cout << "2. Delete Node at Arbitrary Position" << endl;
    cout << "3. Print Current List" << endl;
    cout << "4. Exit Program" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    Node* head = nullptr; 
    int choice;

    insertAtPosition(head, 10, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 30, 3);

    do {

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        
        displayMenu();
        if (!(cin >> choice)) {
            cout << "\n❌ Invalid input. Please enter a number." << endl;
            continue; 
        }

        switch (choice) {
            case 1: { 
                int data, position;
                cout << "\n--- INSERT OPERATION ---" << endl;
                cout << "Enter data to insert: ";
                if (!(cin >> data)) break;
                cout << "Enter 1-based position (1 to " << getLength(head) + 1 << "): ";
                if (!(cin >> position)) break;
                insertAtPosition(head, data, position);
                printList(head);
                break;
            }
            case 2: { 
                int position;
                cout << "\n--- DELETE OPERATION ---" << endl;
                cout << "Current List Length: " << getLength(head) << endl;
                if (getLength(head) == 0) {
                     cout << "List is empty, nothing to delete." << endl;
                     break;
                }
                cout << "Enter 1-based position to delete (1 to " << getLength(head) << "): ";
                if (!(cin >> position)) break;
                deleteAtPosition(head, position);
                printList(head);
                break;
            }
            case 3: {
                printList(head);
                break;
            }
            case 4: { 
                cout << "\nExiting program. Clearing memory... Goodbye! 👋" << endl;
                freeList(head);
                break;
            }
            default: {
                cout << "\n❌ Invalid choice. Please select a number between 1 and 4." << endl;
                break;
            }
        }
         

    } while (choice != 4);

    return 0;
}