/*
Lab Task 2:
Write a program that lets the user enter the total rainfall for 7 days into a doubly linked list. The program should calculate and display the 
•	Total rainfall for the week,
•	The average weekly rainfall, 
•	The day with the highest and lowest amounts.
•	Rainfall of day after 5th node.
 Input Validation: Do not accept negative numbers for weekly rainfall figures
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Add node at end
void add(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Display rainfall list
void display(Node* head) {
    int day = 1;
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Day " << day << ": " << temp->data << " mm" << endl;
        temp = temp->next;
        day++;
    }
}

int main() {
    Node* head = nullptr;
    int rainfall;

    // Input rainfall for 7 days
    cout << "Enter rainfall for 7 days (mm):\n";
    for (int i = 1; i <= 7; i++) {
        do {
            cout << "Day " << i << ": ";
            cin >> rainfall;
            if (rainfall < 0) {
                cout << "Invalid! Rainfall cannot be negative.\n";
            }
        } while (rainfall < 0);
        add(head, rainfall);
    }

    cout << "\nRainfall Data:\n";
    display(head);

    // Calculate total and average
    int total = 0, count = 0;
    int highest = -1, lowest = 1e9;
    int highDay = 0, lowDay = 0;

    Node* temp = head;
    int day = 1;
    while (temp != nullptr) {
        total += temp->data;
        count++;

        if (temp->data > highest) {
            highest = temp->data;
            highDay = day;
        }
        if (temp->data < lowest) {
            lowest = temp->data;
            lowDay = day;
        }

        temp = temp->next;
        day++;
    }

    cout << "\nTotal rainfall for the week: " << total << " mm\n";
    cout << "Average weekly rainfall: " << (total / 7.0) << " mm\n";
    cout << "Day " << highDay << " had the highest rainfall: " << highest << " mm\n";
    cout << "Day " << lowDay << " had the lowest rainfall: " << lowest << " mm\n";

    // Find rainfall after 5th node
    temp = head;
    int pos = 1;
    while (temp != nullptr && pos < 6) {  // move to 6th node
        temp = temp->next;
        pos++;
    }

    if (temp != nullptr) {
        cout << "Rainfall of the day after 5th node (Day 6): " << temp->data << " mm\n";
    } else {
        cout << "There is no node after 5th day!\n";
    }

    return 0;
}