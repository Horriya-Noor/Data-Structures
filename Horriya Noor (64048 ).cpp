/* Lab Task 1:
 
a)	Create a Doubly link list with marks as a node having int type of data. Initialize this list from user input. 
b)	Function called add to insert node at beginning
c)	Function called add to insert node at after 45 value/position
d)	Function called delete to del node at beginning
e)	Function called delete to del node at after 45 value/position
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Add at beginning
void add(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, head};
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

// Add after node with value 45
void add(Node* head, int value, int afterValue) {
    Node* temp = head;
    while (temp != nullptr && temp->data != afterValue) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << afterValue << " not found in list!\n";
        return;
    }
    Node* newNode = new Node{value, temp, temp->next};
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Delete at beginning
void del(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

// Delete node after given value (e.g., 45)
void del(Node* head, int afterValue) {
    Node* temp = head;
    while (temp != nullptr && temp->data != afterValue) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "No node exists after " << afterValue << " to delete!\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next != nullptr) {
        toDelete->next->prev = temp;
    }
    delete toDelete;
}

// Display list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "Enter number of marks: ";
    cin >> n;

    cout << "Enter marks: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        add(head, value);  // inserting at beginning
    }

    cout << "\nInitial List:\n";
    display(head);

    cout << "\nAdding 99 after 45...\n";
    add(head, 99, 45);
    display(head);

    cout << "\nDeleting at beginning...\n";
    del(head);
    display(head);

    cout << "\nDeleting node after 45...\n";
    del(head, 45);
    display(head);

    return 0;
}