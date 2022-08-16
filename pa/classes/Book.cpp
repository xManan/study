#include "Book.h"
#include <string>
#include <iostream>

Book::Book(){
    price_ = 0.0;
    stock_ = 0;
    author_ = "";
    title_ = "";
    publisher_ = "";
}

Book::Book(std::string title, std::string author, std::string publisher, float price, int stock){
    price_ = price;
    stock_ = stock;
    author_ = author;
    title_ = title;
    publisher_ = publisher;
}

float Book::price(){
    return price_;
}

int Book::stock(){
    return stock_;
}

std::string Book::author(){
    return author_;
}

std::string Book::title(){
    return title_;
}

std::string Book::publisher(){
    return publisher_;
}

void Book::display(){
    std::cout 
    << "Title: "<< title_ << '\n'
    << "Author: "<< author_ << '\n'
    << "Price: "<< price_ << '\n'
    << "Publisher: "<< publisher_ << '\n'
    << "Stock: "<< stock_ << '\n';
}
