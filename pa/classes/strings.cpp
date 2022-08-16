#include <iostream>
#include <cstring>

using namespace std;

class str{
    char *p;
    int len;
    public:
    str(): p(NULL), len(0){cout << "constructor1\n";}
    str(const char *c){
        cout << "constructor3\n";
        p = new char[strlen(c)+1];
        strcpy(p,c);
        len = strlen(c);
    }
    str(const str &s){
        cout << "copy constructor\n";
        p = new char[s.len + 1];
        strcpy(p,s.p);
        len = s.len;
    }
    int getlen(){
        return len;
    }
    friend bool operator<=(const str &s1, const str &s2);
};

bool operator<=(const str &s1, const str &s2){
    return s1.len <= s2.len;
}

class Distance{
    int feet;
    int inches;
    public:
    Distance(): feet(0), inches(0){cout << "constructor1\n";}
    Distance(int f, int i): feet(f), inches(i){cout << "constructor2\n";}
    Distance(const Distance &d){
        feet = d.feet;
        inches = d.inches;
        cout << "Copy constructor\n";
    }
    void operator=(const Distance &d){
        cout << "assignment overloading\n";
        feet = d.feet;
        inches = d.inches;
    }
    void display(){
        cout << "Feet: " << feet<<'\n' << "Inches: " << inches << "\n\n";
    }
};

int main(){
    // str s1((char*)"abcdef"), s2((char*)"abc");
    // str s = s1;
    // str ss;
    // ss = s2;
    // cout << s.getlen() << '\n';
    // cout << ss.getlen() << '\n';
    // if(s2 <= s1){
    //     cout << "less\n";
    // } else {
    //     cout << "not less\n";
    // }
    Distance d1(11,2), d2(4,11);
    d1.display();
    d2.display();
    d1 = d2;
    d1.display();
    d2.display();
    Distance d3 = d1;
    Distance d4 = d1;
}
