#include <iostream>

using namespace std;

class Inches;

class Feet{
    public:
    int feet;
    int inches;
    Feet(int f=0, int i=0){
        feet = f;
        inches = i;
    }
    Feet(Inches &i){
        feet = i.inches/12;
        inches = i.inches%12;
    }
    Feet operator=(Inches &i){
        Feet f;
        f.feet = i.inches/12;
        f.inches = i.inches%12;
        return f;
    }
    void display(){
        cout << "f: " << feet << "i: " << inches << '\n';
    }
};

class Inches{
    public:
    int inches;
    Inches(int i=0){
        inches = i;
    }
    Inches(Feet &f){
        inches = f.feet*12 + f.inches;
    }
    Inches operator=(Feet &f){
        Inches tmp;
        tmp.inches = f.feet*12 + f.inches;
        return tmp;
    }
    void display(){
        cout << inches << '\n';
    }
};

int main(){
    Feet f(2,11);
    Inches i(f);
    i.display();
    Inches i2 = f;
    i2.display();
}
