// gp

#include <iostream>
using namespace std;

int main(){
    int n = 5;
    int arr[] = {1,3,4,8,16};
    int diff = arr[1]/arr[0];
    bool flag = false;
    for(int i=2; i<n-1; ++i){
        if(diff != arr[i+1] / arr[i]){
            cout << "not gp\n";
            return 0;
        }
    }
    string str;
    getline(cin ,str);
    cout << "gp\n";
    return 0;
}
