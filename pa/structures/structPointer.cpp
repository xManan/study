#include <iostream>

using namespace std;

struct Book {
    string author;
    string title;
    int price;
    string publisher;
    int stock;
};

// void fun(int *x){
//         int z = 10;
//         x = &z;
// }

int search(struct Book inventory[], int numBooks, string query){
    for(int i=0; i<numBooks; ++i){
        if(inventory[i].title == query) return i;
    }
    return -1;
}

void printBook(struct Book inventory[], int index){
    cout << "Title: "<< inventory[index].title << '\n';
    cout << "Author: "<< inventory[index].author << '\n';
    cout << "Price: "<< inventory[index].price << '\n';
    cout << "Publisher: "<< inventory[index].publisher << '\n';
    cout << "Stock: "<< inventory[index].stock << '\n';
}

int main(){
    // int x = 15;
    // int *y = &x;
    // fun(y);
    // cout << *y << '\n';
    int totalBooks = 100;
    struct Book inventory[totalBooks];
    inventory[0] = {"RL Stine", "Goosebumps", 100, "abc", 15};
    inventory[1] = {"xyz", "Book1", 150, "pop", 12};
    inventory[2] = {"RS Aggarwal", "Mathematics", 200, "bbb", 5};
    inventory[3] = {"RL Stine", "Goosebumps 2", 100, "abc", 25};

    while(1){
        string query;
        cout << "Enter a book you want to buy: ";
        cin >> query;
        int index = search(inventory, totalBooks, query);
        if(index == -1){
            cout << "Book not found !\n";
            continue;
        }
        printBook(inventory, index);
        int need;
        cout << "Enter number of books you buy: ";
        cin >> need;
        if(inventory[index].stock >= need){
            inventory[index].stock -= need;
            cout << "Total Cost: " << inventory[index].stock*inventory[index].price << '\n';
        }
        else{
            cout << "Books not available\n";
        }
    }
}
