#include <iostream>

using namespace std;

void swap(int *a, int *b){
    if (a==b) return;
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[], int start, int end){
    int *pivot = &arr[end];
    int pindex=start;
    for(int i=start; i<=end-1; ++i){
        if(arr[i] < *pivot){
            swap(&arr[i], &arr[pindex]);
            ++pindex;
        }
    }
    swap(&arr[pindex], pivot);
    return pindex;
}

void quicksort(int arr[], int start, int end){
    if(start < end){
        int pindex=partition(arr, start, end);
        quicksort(arr, start, pindex-1);
        quicksort(arr, pindex+1, end);
    }
}

void printarr(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {55,12,45,67,2,32,44,78,8,21};
    int n = sizeof(arr)/sizeof(int);
    quicksort(arr, 0, n-1);
    printarr(arr, n);
}





