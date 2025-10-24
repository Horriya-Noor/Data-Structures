/*Task 2: Data Entry Operator in a company implementation
Suppose, you are working as a Data Entry Operator in a company. You have created a dataset that contains the names of N employees. 
Then your supervisor wants you to add, deleted, update, look/search for a particular employee by name. (Consider, every name in the data set is unique).
Now your task is to write a program using circular singly Link List Data structure which will help you to add, del, find out the details which your 
supervisor is looking for.
If an operation is performed successfully then print an appropriate messages “added/deleted/found successfully”.
*/
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

class EmployeeList {
    Node* last;

public:
    EmployeeList() {
        last = nullptr;
    }

    void addEmployee(string name) {
        Node* newNode = new Node(name);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        cout << name << " added successfully!\n";
    }

    void deleteEmployee(string name) {
        if (last == nullptr) {
            cout << "No employees to delete!\n";
            return;
        }

        Node* curr = last->next;
        Node* prev = last;

        do {
            if (curr->name == name) {
                if (curr == last && curr->next == last) {
                    last = nullptr; // only one node
                } else {
                    prev->next = curr->next;
                    if (curr == last)
                        last = prev;
                }
                delete curr;
                cout << name << " deleted successfully!\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        cout << name << " not found!\n";
    }

    void searchEmployee(string name) {
        if (last == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = last->next;
        do {
            if (temp->name == name) {
                cout << name << " found successfully!\n";
                return;
            }
            temp = temp->next;
        } while (temp != last->next);

        cout << name << " not found!\n";
    }

    void display() {
        if (last == nullptr) {
            cout << "No employees in the list!\n";
            return;
        }

        Node* temp = last->next;
        cout << "\nEmployee List: ";
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(back to start)\n";
    }
};

int main() {
    EmployeeList emp;
    int choice;
    string name;

    cout << "=== Employee Management System using Circular Linked List ===\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Display All Employees\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter employee name to add: ";
                cin >> name;
                emp.addEmployee(name);
                break;
            case 2:
                cout << "Enter employee name to delete: ";
                cin >> name;
                emp.deleteEmployee(name);
                break;
            case 3:
                cout << "Enter employee name to search: ";
                cin >> name;
                emp.searchEmployee(name);
                break;
            case 4:
                emp.display();
                break;
            case 5:
                cout << "Exiting program... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
