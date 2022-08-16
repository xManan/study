#include <iostream>

using namespace std;

class num{
    int x;
    public:
    num(){
        cout << "defaut\n";
        x = 0;
    }
    num(int n){
        cout << "overloaded int arg\n";
        x = n;
    }
    num(bool val){
        cout << "overloaded bool arg\n";
    }
    num(num &n){
        cout << "const copy\n";
    }
    // num(const num &n){
    //     cout << "copy\n";
    // }
    void print(){
        cout << "Value of x: " << x << '\n';
    }
};

int main(){
    // num n1 = 10;
    // while(1);
}




