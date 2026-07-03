#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // First node
    Node* head = new Node();
    head->data = 10;
    head->next = new Node();   // create second node

    // Second node
    head->next->data = 20;
    head->next->next = new Node();  // create third node

    // Third node
    head->next->next->data = 30;
    head->next->next->next = NULL;  // last node

    // Traverse and print
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}