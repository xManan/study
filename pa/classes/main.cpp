#include <iostream>
#include <iomanip>
#include <string>
#include "Inventory.h"

using namespace std;

int main(){
    Inventory inv;
    while(true){
        // cout << "\x1b[2J";
        // cout << "\x1b[1;1H";
        cout 
            << setfill('=') << setw(40) << '\n'
            << '\n'
            << "1. Add new book\n"
            << "2. Display book\n"
            << "3. Display all books\n"
            << "4. Exit\n"
            << '\n'
            << setfill('=') << setw(40) << '\n'
            << "\nEnter your choice: ";
        int choice = 0;
        cin >> choice;
        cin.ignore();
        switch(choice){
            case 1:{
                string title, author, publisher;
                float price;
                int stock;
                cout << '\n';
                cout << "Enter title of the Book: ";
                getline(cin, title);
                cout << "Enter author of the Book: ";
                getline(cin, author);
                cout << "Enter publisher of the Book: ";
                getline(cin, publisher);
                cout << "Enter price of the Book: ";
                cin >> price;
                cout << "Enter stock available: ";
                cin >> stock;
                cout << '\n';
                inv.addBook(title, author, publisher, price, stock);
                break;
            }
            case 2:{
                string title;
                cout << "Enter the title of the book you want to display: ";
                getline(cin, title);
                cout << '\n';
                inv.displayBook(inv.searchBook(title));
                cout << '\n';
                break;
            }
            case 3:
                cout << '\n';
                inv.displayBooks();
                cout << '\n';
                break;
            case 4:
                return 0;
        }
        choice = 0;
    }
}
