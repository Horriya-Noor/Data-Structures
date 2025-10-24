/* Task 1: Circular linked List Task:
Make a circular link list and perform following
•	Function called Insert before to add node at the beginning of Circular Linked list.
•	Function called Insert After to add node at the end of Circular Linked list.
•	Function called delete to del node in Circular Linked List .(consider all cases)
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        cout << val << " inserted at beginning.\n";
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        cout << val << " inserted at end.\n";
    }

    // Delete a node
    void deleteNode(int val) {
        if (last == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = last->next;
        Node* prev = last;

        // Case 1: only one node
        if (curr == last && curr->data == val) {
            delete curr;
            last = nullptr;
            cout << val << " deleted successfully.\n";
            return;
        }

        // Case 2: first node
        if (curr->data == val) {
            prev->next = curr->next;
            delete curr;
            cout << val << " deleted successfully.\n";
            return;
        }

        // Case 3: middle or last node
        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == val) {
                prev->next = curr->next;
                if (curr == last)
                    last = prev;
                delete curr;
                cout << val << " deleted successfully.\n";
                return;
            }
        } while (curr != last->next);

        cout << "Value " << val << " not found!\n";
    }

    // Display all nodes
    void display() {
        if (last == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value;

    do {
        cout << "\n==== Circular Linked List Menu ====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete Node\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            cll.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            cll.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            cll.deleteNode(value);
            break;
        case 4:
            cll.display();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}