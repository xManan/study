#include <iostream>
 using namespace std;
class Complex{
    double re, im;
public:
    Complex(double r=0, double i=0): re(r), im(i){}
    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator+(const Complex &c1, double n);
    friend Complex operator+(double n, const Complex &c1);
    friend std::ostream& operator<<(std::ostream &dout, const Complex &c);
    friend std::istream& operator>>(std::istream &din, Complex &c);
    void display();
};

Complex operator+(const Complex &c1, const Complex &c2){
    return Complex(c1.re + c2.re, c1.im + c2.im);
}

Complex operator+(const Complex &c1, double n){
    return Complex(c1.re + n, c1.im + n);
}

Complex operator+(double n, const Complex &c1){
    return Complex(c1.re + n, c1.im + n);
}

std::ostream& operator<<(std::ostream &dout, const Complex &c){
    dout << c.re << " + " << c.im << "i\n";
    return dout;
}

std::istream& operator>>(std::istream &din, Complex &c){
    din >> c.re >> c.im;
    return din;
}

void Complex::display(){
    std::cout << re << " + " << im << "i\n";
}

int main(){
    Complex c;
    cin >> c;
    cout << c;
}



