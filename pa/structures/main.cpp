#include <iostream>

using namespace std;

struct Student {
    double roll;
    float cgpa;
    char gender;
};

struct Product {
    int weight;
    float price;
};

int main(){
    int prodCount;
    cout << "Enter number of Products:";
    cin >> prodCount;
    struct Product products[prodCount];
    for(int i=0; i<prodCount; ++i){
        struct Product p;
        cout << "Enter weight and price: ";
        cin >> p.weight >> p.price;
        products[i] = p;
    }
    for(int i=0; i<prodCount; ++i){
        cout << products[i].weight << ' ' << products[i].price << '\n';
    }
}
