#include <iostream>

using namespace std;

class A{
public:
    int num;
};

class B:public A{

};

class C:public A{

};

class D: public B, public C{

};

int main(){
    D obj;
    cout << "Inside main function\n";
    cout << "Val of num: " << obj.B::num << '\n';
}
