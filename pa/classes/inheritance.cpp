#include <iostream>

using namespace std;

class POP{

};

class ABC{
public:
    int *a;
    bool b;
    ABC(): a(nullptr), b(true){
        cout << "default constructor\n";
    }
    ABC(int *a, bool b=true): a(a), b(b){
        cout << "overloaded constructor\n";
    }
    ABC(const ABC &abc){
        cout << "Copy constructor\n";
    }
    ABC operator=(const ABC &abc){
        cout << "Assignment overloading\n";
        ABC temp;
        // int arr[4] = {1,2,3,4};
        // temp.a = arr;
        // temp.b = false;
        // return abc;
        return temp;
    }
};

ABC func(){
    ABC a;
    return a;
}

int main(){
    // int p[] = {1,2,3,4};
    // cout << "Address of p: " << p << '\n';
    // ABC a = p;
    // ABC b = a;
    // ABC c = a;
    // ABC d;
    // d = a;
    // cout << a.a << ' ' << b.a << ' ' << c.a << ' ' << d.a << '\n';
    ABC x = func();
    ABC y = x;
    ABC z;
    z = y;
}
