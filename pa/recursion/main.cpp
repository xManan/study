#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
T add(T a, T b, T c=0, T d=0, T e=0){
    return a+b+c+d+e;
}

void recur(int i){
    if(i <= 0) return;
    recur(i-1);
    cout << i << endl;
}

long factorial(long a){
    if(a > 1)
        return a*factorial(a-1);
    else 
        return 1;
}

int sumOfDigits(int num){
    if(num == 0) return 0;
    return num%10 + sumOfDigits(num/10);
}

void printPattern(int n){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            cout << '*';
        }
        cout << '\n';
    }
}

void printPatternRev(int n){
    for(int i=1; i<=n; ++i){
        for(int j=n-i; j>=0; --j){
            cout << '*';
        }
        cout << '\n';
    }
}
int main(){
    printPattern(5);
    printPattern(9);
    printPatternRev(5);
}
