#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void printArr(int *arr, int n){
    for (int i=0; i<n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main(){
    int arr[10];
    fill_n(arr,10,9);
    printArr(arr,10);
}
