#include<iostream>
using namespace std;
const int size = 3;
class Vector
{
private:
    /* data */
    int v[size];
public:
    Vector();

    Vector(int *x);
    friend Vector operator + (int a,Vector b);
    friend Vector operator + (Vector a,int b);
    friend istream & operator << (istream &,Vector &);
    friend ostream & operator << (ostream &,Vector &);

};
Vector::Vector(){
    for(int i = 0; i <size;i++){
        v[i] = 0;
    }
}
Vector::Vector(int *x){
    for(int i = 0; i <size;i++){
        v[i] = x[i];
    }
}

ostream& operator<<(ostream &dout, Vector &b){
    dout << "-->> " << b.v[0];
    for(int i=1; i<size; ++i){
        dout << "," << b.v[i];
    }
    dout << '\n';
    return dout;
}

int main(){
    Vector m;
    int x[] = {1,2,3};
    cout << m;
    return 0;
}
