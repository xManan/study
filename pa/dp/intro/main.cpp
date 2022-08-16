#include <algorithm>
#include <iostream>

#define ll long long
#define MAX_N 100

using std::cout;

int cache[MAX_N];

ll fibonacciR(ll n){
    if(n < 2) 
        return n;
    if(cache[n] == -1){
        ll res = fibonacciR(n-1) + fibonacciR(n-2);
        cache[n] = res;
        return res;
    }
    return cache[n];
}

ll fibonacci(ll n){
    cache[0] = 0;
    cache[1] = 1;
    for(ll i=2; i<=n; ++i){
        if(cache[i] == -1){
            cache[i] = cache[i-1] + cache[i-2];
        }
    }
    return cache[n];
}

int main(){
    std::fill_n(cache, MAX_N, -1);
    // cout << fibonacciR(60) << '\n';    
    // cout << fibonacciR(30) << '\n';    
    cout << fibonacci(60) << '\n';    
    cout << fibonacci(30) << '\n';    
}
