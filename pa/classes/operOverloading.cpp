#include <iostream>

using namespace std;

class Airthmetic{
    int a;
    int b;
    public:
    Airthmetic(int a=0, int b=0){
        this->a = a;
        this->b = b;
    }
    Airthmetic operator+(const Airthmetic &b){
        return (Airthmetic){this->a + b.a, this->b + b.b};
    }
    void print(){
        cout << "a: " << this->a << endl;
        cout << "b: " << this->b << endl;
    }
};

int main(){
    Airthmetic a1(1,2),a2(9,8);
    Airthmetic res = a1+a2;
    res.print();
}
