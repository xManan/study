#include <iostream>

using namespace std;

class temp{
    int a,b;
    public:
    temp(int a=0, int b=1){
        cout << "dc\n";
        this->a = a;
        this->b = b;
    }
    temp(temp& t){
        cout << "cc\n";
        this->a = t.a;
        this->b = t.b;
    }
};

int main(){
    temp t1;
    temp t2 = t1;
    temp t3(t1);
    temp t4;
    t4 = t1;
    temp t5(2,3);
}
