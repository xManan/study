#include <iostream>

using namespace std;

void printPattern(int n){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            cout << j;
        }
        for(int j=i+1; j<=2*n-i; ++j){
            cout << ' ';
        }
        for(int j=i; j>=1; --j){
            cout << j;
        }
        cout <<  '\n';
    }
}

void printPattern1(int n){
    for(int i=1; i<=n; ++i){
        for(int j=n; j>i; --j){
            cout << ' ';
        }
        for(int j=1; j<=2*i-1; ++j){
            cout << j;
        }
        for(int j=n; j>i; --j){
            cout << ' ';
        }
        cout << '\n';
    }
    for(int i=0; i<n-1; ++i){
        for(int j=1; j<=i+1; ++j){
            cout << ' ';
        }
        for(int j=1; j<=2*(n-i)-3; ++j){
            cout << j;
        }
        cout << '\n';
    }
}

// int* fun(){
//     int x=10;
//     return &x;
// }

void fun(int *n){
    int x=10;
    n = &x;
}

int main(){
    // int n = 5;
    // printPattern(5); 
    // printPattern1(5); 
    // int *n = fun();
    // cout << *n << '\n';
    int *m;
    fun(m);
    cout << *m;
}
