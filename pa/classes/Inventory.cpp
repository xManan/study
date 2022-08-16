#include "Inventory.h"
#include <string>
#include <iostream>

Inventory::Inventory(){
    currBooks = 0;
    numBooks = 100;
    Book tmp[numBooks];
    books = tmp;
}

Inventory::Inventory(int n){
    currBooks = 0;
    numBooks = n;
    Book tmp[numBooks];
    books = tmp;
}

void Inventory::addBook(std::string title, std::string author, std::string publisher, float price, int stock){
    Book b(title, author, publisher, price, stock);
    books[currBooks] = b;
    ++currBooks;
}

int Inventory::searchBook(std::string title){
    for(int i=0; i<currBooks; ++i){
        if(books[i].title() == title){
            return i;
        }
    } 
    return -1;
}

void Inventory::displayBooks(){
    for(int i=0; i<currBooks; ++i){
        books[i].display();
        std::cout << '\n';
    }
}

void Inventory::displayBook(int index){
    if(index != -1)
        books[index].display();
    std::cout << '\n';
}
