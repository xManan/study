#include <iostream>
#include <string>

using namespace std;

bool isin(char c, char arr[], int k){
    for(int i=0; i<k; ++i){
        if(arr[i] == c) return true;
    }
    return false;
}

long long sum(int n){
    return (n*(n+1))/2;
}

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin.ignore();
    getline(cin, s);
    char c[k];
    for(int i=0; i<k; ++i){
        cin >> c[i];
    }
    int start = 0;
    int end = 0;
    long long ans = 0;
    for(int i=0; i<n; ++i){
        if(isin(s[i],c,k)){
            ++end; 
        } else {
            ans += sum(end-start);
            start = end = i;
        }
    }
    ans += sum(end-start);
    cout << ans << endl;
}
