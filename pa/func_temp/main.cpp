#include <iostream>

using namespace std;

template <class T>
T sum(T a, T b){
    return a+b;
}

int main(){
    int x=10,y=2;
    float a=1.9,b=2.7;
    cout << sum<int>(x,y) << ' ' << sum<float>(a,b) << '\n';
}
