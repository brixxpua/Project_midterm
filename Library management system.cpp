#include <iostream>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    string year;

public:
    Book(string title, string author, string year) {
        this->title = title;
        this->author = author;
        this->year = year;
    }

    ~Book() {
       
    }

    void display() {
        cout << "\nTitle: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    vector<Book> books;  
    int choice;

    do {
        cout << "1. Add a Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1: { 
                string title, author, year;

                cout << "\nEnter Book Details: " << endl;
                cout << "Title: ";
                getline(cin, title);
                cout << "Author: ";
                getline(cin, author);
                cout << "Release Date: ";
                getline(cin, year);

                books.push_back(Book(title, author, year));  
                cout << "\nBook added \n" << endl;
                break;
            }

            case 2: { 
                if (books.empty()) {
                    cout << "\nNothing to display" << endl;
                } else {
                    for (auto &book : books) {
                        book.display();
                    }
                }
                break;
            }

            case 3: // Exit
                cout << "\nExiting program.\n";
                break;

            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 3.\n";
        }
    } while (choice != 3);

    return 0;
}
