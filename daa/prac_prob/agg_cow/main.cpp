#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your codejj
    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n >> c;
        cout << n << " " << c << endl;
        //cout << "";
        int arr[n];
        for(int i=0; i<n; ++i) cin >> arr[i];
        sort(arr, arr+n);
        int min_dist = 1;
        bool flag = true;
        while(flag){
            int index=1;
            int last_placed=0;
            for(int i=1; i<c; ++i){
                while(arr[index]-arr[last_placed] < min_dist){
                    if(index > n){
                        flag = false;
                        break;
                    }
                    index++;
                }
                last_placed = index;
                index++;
            }
            //cout << last_placed << " " << index << endl;
            min_dist++;
        }
     	cout << min_dist-2 << endl;   
    }
    return 0;
}
