#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book{
    float price_;
    int stock_;
    std::string author_, title_, publisher_;
    public:
    Book();
    Book(std::string, std::string, std::string, float, int);
    void display();  
    float price();
    int stock();
    std::string author(), title(), publisher();
};

#endif 

