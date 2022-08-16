#include <iostream>

using namespace std;

void printarr(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotateClockwise(int arr[], int n){
    int temp = arr[n-1];
    for(int i=n-1; i>=0; --i){
        arr[i] = arr[i-1]; 
    }
    arr[0] = temp;
}

void rotateAntiClockwise(int arr[], int n){
    int temp = arr[0];
    for(int i=0; i<n-1; ++i){
        arr[i] = arr[i+1]; 
    }
    arr[n-1] = temp;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    // int x;
    // cin >> x;
    // int index;
    // for(int i=0; i<n; ++i){
    //     if(arr[i] == x){
    //         index = i;
    //         for(int j=i; j<n; ++j){
    //             arr[j] = arr[j+1];
    //         }
    //     }
    // }
    // printarr(arr,n-1);
    // for(int i=n; i>=index; --i){
    //     arr[i] = arr[i-1];
    // }
    // int y;
    // cin >> y;
    // arr[index] = y;
    printarr(arr,n);
    //rotateClockwise(arr, n);
    rotateAntiClockwise(arr, n);
    printarr(arr,n);
}
