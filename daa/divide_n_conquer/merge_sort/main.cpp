#include <iostream>

using namespace std;

void printarr(int arr[], int n);

void merge(int arr[], int low, int mid, int high){  
    int n1=mid-low+1;
    int n2=high-mid;
    int a1[n1];
    int a2[n2];
    for(int i=0; i<n1; ++i){
        a1[i] = arr[low+i];
    }
    for(int i=0; i<n2; ++i){
        a2[i] = arr[mid+1+i];
    }
    int i,j;
    i=j=0;
    int k = low;
    while(i<n1 && j<n2){
        if(a1[i] < a2[j]){
            arr[k] = a1[i]; 
            ++i;
        }
        else{
            arr[k] = a2[j];
            ++j;
        }
        ++k;
    }
    while(i<n1){
        arr[k] = a1[i];
        ++i;
        ++k;
    }
    while(j<n2){
        arr[k] = a2[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
    //cout << "low: " << low << " high: " << high << endl;
}

void printarr(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {67,45,22,90,6,12,32,78,8,34};
    int n = sizeof(arr)/sizeof(int);
    printarr(arr, n);
    mergeSort(arr, 0, n-1);
    printarr(arr, n);
}
