// palindrome code

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string str = "triangle";
    string str1 = "integral";
    sort(str.begin(),  str.end());
    sort(str1.begin(), str1.end());
    cout << str << ' ' << str1 << '\n';
}

