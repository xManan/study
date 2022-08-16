#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <string>

class Inventory{
    Book *books;
    int numBooks;
    int currBooks;
    public:
    Inventory();
    Inventory(int);
    void addBook(std::string, std::string, std::string, float, int);
    int searchBook(std::string);
    void displayBooks();
    void displayBook(int);
};

#endif
