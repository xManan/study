#include <iostream>

using namespace std;

class Rect{
    int w,h;
    public:
    Rect(){
        w=h=0;
    }
    Rect(int x, int y): w(x), h(y){}
    int area(){return w*h;}
    friend Rect duplicate(const Rect&);
    friend Rect compare(const Rect&, const Rect&);
};

Rect duplicate(const Rect& r){
    return Rect(r.w, r.h);
}

Rect compare(const Rect& r1, const Rect& r2){
    if(r1.w > r2.w){
        if(r1.h > r2.h){
            return r1;
        } 
    } else if(r2.w > r1.w){
        if(r2.h > r1.h){
            return r2;
        }
    }
    if(r2.h > r1.h) return r2;
    return r1;
}

int main(){
    Rect r1(2,3);
    Rect r2 = duplicate(r1);
    cout << r1.area() << endl;
    cout << r2.area() << endl;
}
