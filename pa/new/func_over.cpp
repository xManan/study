#include <iostream>

using namespace std;

int sum(int a, int b){
    return a+b;
}

int sum(int a, int b, int c){
    return a+b+c;
}

int sum(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(){
    int a=10, b=12, c=8;
    int arr[5] = {4,6,2,8,5};

    cout << sum(a,b) << '\n';
    cout << sum(a,b,c) << '\n';
    cout << sum(arr,5) << '\n';
}
