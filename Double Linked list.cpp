#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void printList(Node* node) {
    if (!node) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    std::cout << "List: ";
    while (node) {
        std::cout << node->data << " <-> ";
        node = node->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Inserting a node at a given position
void insertAtPosition(Node*& head, int data, int position) {
    Node* newNode = new Node(data);
    if (position == 1) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; temp && i < position - 1; ++i) {
        temp = temp->next;
    }
    if (!temp) {
        std::cout << "Invalid position. Insertion failed." << std::endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

// Deleting a node at a given position
void deleteAtPosition(Node*& head, int position) {
    if (!head) {
        std::cout << "List is empty. Deletion failed." << std::endl;
        return;
    }
    Node* temp = head;
    if (position == 1) {
        head = temp->next;
        if (head) head->prev = nullptr;
        delete temp;
        return;
    }
    for (int i = 1; temp && i < position; ++i) {
        temp = temp->next;
    }
    if (!temp) {
        std::cout << "Invalid position. Deletion failed." << std::endl;
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}
int main() {
    Node* head = nullptr;
    int choice, data, position;

    while (true) {
        std::cout << "\nDoubly Linked List Operations:" << std::endl;
        std::cout << "1. Insert at a position" << std::endl;
        std::cout << "2. Delete at a position" << std::endl;
        std::cout << "3. Print list" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter data to insert: ";
                std::cin >> data;
                std::cout << "Enter position to insert at: ";
                std::cin >> position;
                insertAtPosition(head, data, position);
                break;
            case 2:
                std::cout << "Enter position to delete: ";
                std::cin >> position;
                deleteAtPosition(head, position);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                // Clean up memory before exiting
                while (head) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
                std::cout << "Exiting program. Memory cleaned up." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}