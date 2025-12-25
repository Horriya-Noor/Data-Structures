#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int id;
    Node* next;
    Node* prev;
};

void Queue() {
    Node* front = NULL;
    Node* rear = NULL;

    for (int i = 1; i <= 7; i++) {
        Node* newNode = new Node;
        newNode->id = i;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    cout << "\n--- Applicants Queue ---\n";
    cout << "Initial line: ";
    for (Node* t = front; t != NULL; t = t->next)
        cout << t->id << endl;

    Node* temp = front->next;
    cout << "Applicant " << temp->id << " left due to urgency."<<endl;
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;

    cout << "After removing 2nd applicant: ";
    for (Node* t = front; t != NULL; t = t->next)
        cout << t->id << endl;

    temp = front;
    front = front->next;
    if (front != NULL)
        front->prev = NULL;
    cout << "Applicant " << temp->id << " gave test and left."<< endl;
    delete temp;

    Node* newNode = new Node;
    newNode->id = 8;
    newNode->next = NULL;
    newNode->prev = rear;
    rear->next = newNode;
    rear = newNode;

    cout << "Final line: ";
    for (Node* t = front; t != NULL; t = t->next)
        cout << t->id << endl;
}

void garage_System() {
    queue<int> road;
    stack<int> garage;

    cout << "\n--- Garage System ---\n";

    road.push(1);
    road.push(2);
    road.push(3);
    cout << "Trucks on road: 1 2 3\n";

    int t = road.front(); road.pop();
    garage.push(t);
    cout << "Truck " << t << " entered garage.\n";

    t = road.front(); road.pop();
    garage.push(t);
    cout << "Truck " << t << " entered garage.\n";

    cout << "Trucks in garage: ";
    stack<int> temp = garage;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    int id = 1;
    if (garage.top() == id) {
        cout << "Truck " << id << " exited garage.\n";
        garage.pop();
    } else {
        cout << "Error: Truck " << id << " is not near garage door.\n";
    }

    id = 2;
    if (garage.top() == id) {
        cout << "Truck " << id << " exited garage.\n";
        garage.pop();
    } else {
        cout << "Error: Truck " << id << " is not near garage door.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n==============================\n";
        cout << "1. Applicants Queue (Doubly Linked List)\n";
        cout << "2. Garage System (Queue + Stack)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Queue();
                break;
            case 2:
                garage_System();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}