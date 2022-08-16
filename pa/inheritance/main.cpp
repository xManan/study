#include <cstdio>
#include <iostream>

using namespace std;

class Enemy{
    public:
    virtual void defense()=0;
    virtual void attack(){
        cout << "This is Enemy class\n";
    }
};

class Monster: public Enemy{
    public:
    void attack(){
        cout << "This is Monster class\n";
    }
};

class Ninja: public Enemy{
    public:
    void attack(){
        cout << "This is Ninja class\n";
    }
};

class abc{
    public:
    int x;
    mutable int y;
    abc(int x=0, int y=0): x(x), y(y){}
    void dis(){
        cout << "dis\n";
    }
    void dis1() const {
        cout << "dis const\n";
    }
};

int func(int x, int n, int lvl){
    if(x < 1 || x > n)
        return lvl-1;
    int a = x-lvl;
    int b = x+lvl;
    int l1 = func(a, n, lvl+1);
    int l2 = func(b, n, lvl+1);
    return max(l1, l2);
}

string operator*(string str, int n){
    string res="";
    while(n--)
        res.insert(0,str);
    return res;
}

int main(){
    string s;
    cin >> s;
}
