/*Task 3:
Write a program that demonstrate add, update, delete and print operation on circular linked list. 
a. You need to have a class Book with attributes(bookId:string, bookName:char,  bookPrice:double, 
bookAuthor:char and bookISBN:string). Also provide getters and setters for class private member variables. 
b. Make a class Node that contains book object as a class private member variable. 
The node class also contains Node next pointer.
c. Provide default and parameterized constructor, getters and setters for both book 
and pointer, 
d. Make a class BookList (act as a Doubly Circular LinkedList class) that provides following 
methods
•	void addBook(bookId:string, bookName:char, bookPrice:double, bookAuthor:char, 
•	bookISBN:string) 
•	void removeBook(bookId:string) 
•	void updateBook(bookId:string, bookName:char, bookPrice:double, bookAuthor:char
•	and bookISBN:string) 
•	void printBooks() 
•	void printBook(bookId:string) //it prints the required book
e. Write main function where you call all the methods in following order 
•	Call addBook method 10 times
•	Now call print book method 1 time
•	Call remove book method 2 time (1 with valid bookId and other with 
•	invalid book id)
•	Now call print book method 1 time
•	Call updateBook method followed by print book
*/
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string bookId;
    string bookName;
    double bookPrice;
    string bookAuthor;
    string bookISBN;

    Book() {}
    Book(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }
};

class Node {
public:
    Book book;
    Node* next;

    Node(Book b) {
        book = b;
        next = nullptr;
    }
};

class BookList {
private:
    Node* head;

public:
    BookList() {
        head = nullptr;
    }

    void addBook(string id, string name, double price, string author, string isbn) {
        Book b(id, name, price, author, isbn);
        Node* newNode = new Node(b);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Book added successfully!\n";
    }

    void removeBook(string id) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        do {
            if (curr->book.bookId == id) {
                if (prev == nullptr) {
                    if (curr->next == head) {
                        delete curr;
                        head = nullptr;
                    } else {
                        Node* temp = head;
                        while (temp->next != head)
                            temp = temp->next;
                        temp->next = head->next;
                        head = head->next;
                        delete curr;
                    }
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                cout << "Book deleted successfully!\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Book ID not found!\n";
    }

    void updateBook(string id, string name, double price, string author, string isbn) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        do {
            if (temp->book.bookId == id) {
                temp->book.bookName = name;
                temp->book.bookPrice = price;
                temp->book.bookAuthor = author;
                temp->book.bookISBN = isbn;
                cout << "Book updated successfully!\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Book ID not found!\n";
    }

    void printBooks() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "\nBooks in List:\n";
        do {
            cout << "ID: " << temp->book.bookId
                 << ", Name: " << temp->book.bookName
                 << ", Price: " << temp->book.bookPrice
                 << ", Author: " << temp->book.bookAuthor
                 << ", ISBN: " << temp->book.bookISBN << endl;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void printBook(string id) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->book.bookId == id) {
                cout << "\nBook Details:\n";
                cout << "ID: " << temp->book.bookId
                     << ", Name: " << temp->book.bookName
                     << ", Price: " << temp->book.bookPrice
                     << ", Author: " << temp->book.bookAuthor
                     << ", ISBN: " << temp->book.bookISBN << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Book ID not found!\n";
    }
};

int main() {
    BookList list;
    int choice;
    string id, name, author, isbn;
    double price;

    do {
        cout << "\n=== Book Management System ===\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Update Book\n";
        cout << "4. Print All Books\n";
        cout << "5. Print Specific Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear newline character

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                getline(cin, id);
                cout << "Enter Book Name: ";
                getline(cin, name);
                cout << "Enter Book Price: ";
                cin >> price;
                cin.ignore();
                cout << "Enter Book Author: ";
                getline(cin, author);
                cout << "Enter Book ISBN: ";
                getline(cin, isbn);
                list.addBook(id, name, price, author, isbn);
                break;

            case 2:
                cout << "Enter Book ID to delete: ";
                getline(cin, id);
                list.removeBook(id);
                break;

            case 3:
                cout << "Enter Book ID to update: ";
                getline(cin, id);
                cout << "Enter new Book Name: ";
                getline(cin, name);
                cout << "Enter new Book Price: ";
                cin >> price;
                cin.ignore();
                cout << "Enter new Book Author: ";
                getline(cin, author);
                cout << "Enter new Book ISBN: ";
                getline(cin, isbn);
                list.updateBook(id, name, price, author, isbn);
                break;

            case 4:
                list.printBooks();
                break;

            case 5:
                cout << "Enter Book ID to display: ";
                getline(cin, id);
                list.printBook(id);
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
