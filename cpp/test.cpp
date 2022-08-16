#include <iostream>

using namespace std;

class Shape{
    public:
    virtual int perimeter(int,int)=0;
    int area(int,int);
};

class Square: public Shape {
    public:
    int side;
    Square(int side){
        this->side = side;
    }
    int perimeter(int a, int b){
        return a+b;
    }
};

class Triangle: public Shape {
   public:
   int a,b,c;
   Triangle(int a, int b, int c){
   }
}

int main(){
    Square s(10);
    return 0;
}
