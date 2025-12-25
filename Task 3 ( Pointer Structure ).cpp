/*Define a Student structure with id, name, and marks.
?	Create a structure variable and a pointer to it.
?	Access and modify members using the pointer (->).
?	Pass the structure pointer to a function that updates marks.
*/
#include <iostream>
#include <string>
using namespace std;

//  Student structure
struct Student {
    int id;
    string name;
    double marks;
};

// student's marks using a pointer
void updateMarks(Student* s, double newMarks) {
    s->marks = newMarks;
}

int main() {
// structure variable and a pointer to it
    Student student1 = {298, "Aliza", 85.5};
    Student* studentPtr = &student1;

// Access and modify members using the pointer

    cout << "Information:" << endl;
    cout << "ID: " << studentPtr->id << endl;
    cout << "Name: " << studentPtr->name << endl;
    cout << "Marks: " << studentPtr->marks << endl;
    cout << "---" << endl;

// Modify the marks directly using the pointer
    studentPtr->marks = 90.0;
    cout << "Data after direct modification:" << endl;
    cout << "Marks: " << student1.marks << endl;
    cout << "---" << endl;

//  Pass the structure pointer to a function that updates marks
    updateMarks(studentPtr, 95.0);
    cout << "Final Data:" << endl;
    cout << "Marks: " << student1.marks << endl;

    return 0;
}