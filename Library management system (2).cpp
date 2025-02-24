#include<iostream>
#include<vector>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int ReleaseDate;
    string genre;
    double rating;

public:
	// Constructor
    Book(string title, string author, int ReleaseDate, string genre, double rating)
    {
        this->title = title;
        this->author = author;
        this->ReleaseDate = ReleaseDate;
        this->genre = genre;
        this->rating = rating;
        
    }
    
    ~Book()
    {
    	cout<< "Destructor: " <<title << endl;
	}

    void display ()
    {
        cout << "Book name: " << title << endl;
        cout << "Book author: " << author << endl;
        cout << "Book release date: " << ReleaseDate << endl;
        cout << "Book genre: " << genre << endl;
        cout << "Book rating: " << rating << endl;
    }

    
};

int main ()
{
	vector<Book> books;
	int n; 
	
	string title;
	string author;
	string ReleaseDate;
	string genre;
	double rating;
	getline(cin, author);
	
	cin.ignore();
	
	for (int i=0; i < n; i++){
		string title, author,ReleaseDate, genre;
		double rating;
	}	
	cout << "\nEnter Book Title " << i + 1 << ":" << endl;-+
	cout <<"Title: ";
	getline(cin, title);
	
	cout << "Enter Author: ";
	getline(cin, author);
	
	cout << "Enter Release date: ";
	getline(cin, ReleaseDate); 
	
	cout << "Enter Genre: ";
	getline(cin, genre);
	
	cout << "Enter rating: ";
	getline(cin, rating);
	cin.ignore();
	
	Book.push_back(books(title, author, ReleaseDate, genre, rating));
	
    Book wimpykid ("Diary of a Wimpy Kid", "Jeff Kinney", 2007, "Humor", 4.6);
    wimpykid.display();
}
