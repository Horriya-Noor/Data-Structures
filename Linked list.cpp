#include <iostream>
using namespace std;

struct Node {
    int data;    
    Node* next;   
    Node(int d) : data(d), next(nullptr) {}  
};

Node* head = nullptr;  
void insertAtBeginning(int d) {
    Node* n = new Node(d); 
    n->next = head;         
    head = n;               
    cout << "Inserted " << d << " at beginning.\n";
}

void insertAtEnd(int d) {
    Node* n = new Node(d);  
    if (!head)              
        head = n;
    else {
        Node* temp = head;
        while (temp->next)  
            temp = temp->next;
        temp->next = n;     
    }
    cout << "Inserted " << d << " at end.\n";
}
void insertAtPosition(int d, int pos) {
    if (pos < 1) {          
        cout << "Invalid position.\n";
        return;
    }
    if (pos == 1) {        
        insertAtBeginning(d);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (!temp) {            
        cout << "Position out of bounds.\n";
        return;
    }
    Node* n = new Node(d);  
    n->next = temp->next;   
    temp->next = n;         
    cout << "Inserted " << d << " at position " << pos << ".\n";
}

void deleteAtBeginning() {
    if (!head) {            
        cout << "List empty.\n";
        return;
    }
    Node* temp = head;    
    head = head->next;     
    cout << "Deleted " << temp->data << " from beginning.\n";
    delete temp;            
}

void deleteAtEnd() {
    if (!head) {            
        cout << "List empty.\n";
        return;
    }
    if (!head->next) {    
        cout << "Deleted " << head->data << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    cout << "Deleted " << temp->next->data << " from end.\n";
    delete temp->next;      
    temp->next = nullptr;   
}

void deleteAtPosition(int pos) {
    if (!head || pos < 1) { 
        cout << "Invalid position or list empty.\n";
        return;
    }
    if (pos == 1) {         
        deleteAtBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (!temp || !temp->next) {  
        cout << "Position out of bounds.\n";
        return;
    }
    Node* toDelete = temp->next; 
    temp->next = toDelete->next; 
    cout << "Deleted " << toDelete->data << " from position " << pos << ".\n";
    delete toDelete;            
}

void display() {
    if (!head) {            
        cout << "List empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp) {         
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, data, pos;
    while (true) {
        cout << "\nMenu:\n"
             << "1. Insert at Beginning\n"
             << "2. Insert at End\n"
             << "3. Insert at Specific Position\n"
             << "4. Delete at Beginning\n"
             << "5. Delete at End\n"
             << "6. Delete at Specific Position\n"
             << "7. Display List\n"
             << "8. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                while (head)
                    deleteAtBeginning();
                cout << "Exiting.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
