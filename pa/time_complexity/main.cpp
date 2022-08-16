#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define loop(x) for(int _i = 0; _i<x; ++_i)

template <class T>
void arrInp(T arr[], int size){
    for(int i=0; i<size; ++i)
        cin >> arr[i];
}

template <class T>
void printArr(T arr[], int size){
    for(int i=0; i<size; ++i)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    int n, x;
	    cin >> n >> x;
	    int arr[n];
	    arrInp<int>(arr, n);
	    int sum = 0;
	    loop(n)
	        sum += arr[_i];
	}
	return 0;
}
