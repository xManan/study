#include <iostream>

using namespace std;

inline int sum(int a, int b){
    return a+b;
}

int main(){
    int x=10, y=11;
    int ans = sum(x,y);
    cout << ans << '\n';
}
