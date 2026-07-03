#include <iostream>
#include <string>
using namespace std;

// Simple class
class Student {
    string name;
    int age;
public:
    Student() : name("NoName"), age(0) {} // default constructor

    void setData(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    // Step 1: Allocate dynamic array of objects
    Student* students = new Student[n];

    // Step 2: Input data
    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cout << "Enter name and age for student " << i+1 << ": ";
        cin >> name >> age;
        students[i].setData(name, age);
    }

    // Step 3: Display data
    cout << "\nStudent List:\n";
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    // Step 4: Free memory
    delete[] students;

    return 0;
}