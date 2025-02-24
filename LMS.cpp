#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Books{
private:
    string title;
    string author;
    string releaseDate;
    string genre;
    double rating;

public:
    Books(string title, string author, string releaseDate, string genre, double rating){
        this->title = title;
        this->author = author;
        this->releaseDate = releaseDate;
        this->genre = genre;
        this->rating = rating;
    }

    void display(){
        cout << "--------------Books---------------" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Release Date: " << releaseDate << endl;
        cout << "Genre: " << genre << endl;
        cout << "Rating: " << rating << endl;
        cout << "-----------------------------------" << endl;
    }

    ~Books(){
        cout << "------Book has been deleted--------" << endl;
    }
};

int main(){
    vector<Books> books;
    int choice;
    string title;
    string author;
    string releaseDate;
    string genre;
    double rating;
    char addAnother;

    do {
        cout << "Enter your choice (1. Add Books, 2. Display Books, 4. Exit): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                do {
                    cout << "Enter the book title: ";
                    getline(cin, title);
                    cout << "Enter the author: ";
                    getline(cin, author);
                    cout << "Enter the release date: ";
                    getline(cin, releaseDate);
                    cout << "Enter the genre: ";
                    getline(cin, genre);
                    cout << "Enter the rating: ";
                    cin >> rating;
                    cin.ignore();

                    books.push_back(Books(title, author, releaseDate, genre, rating));

                    cout << "Add another book (y/n): ";
                    cin >> addAnother;
                    cin.ignore();
                } while (addAnother == 'y' || addAnother == 'Y');
                break;
            case 2:
                for (auto& book : books) {
                    book.display();
                }
                break;
            case 4:
                books.clear();
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}


