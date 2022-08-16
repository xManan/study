#include <iostream>

using namespace std;

void output(int,float);
void output(int*,float*);

int main(){
    int rollno;
    float cgpa;
    cout << "Enter Values:";
    cin >> rollno >> cgpa;
    output(rollno, cgpa);
    cout << "Roll No:" << rollno << '\n';
    cout << "CGPA" << cgpa << '\n';
    output(&rollno, &cgpa);
    cout << "Roll No:" << rollno << '\n';
    cout << "CGPA" << cgpa << '\n';
    return 0;
}

void output(int r, float c){
    cout << "Roll No:" << r+1 << '\n';
    cout << "CGPA" << c+0.1 << '\n';
}

void output(int *r, float *c){
    *r=*r+1;
    *c=*c+0.1;
    cout << sizeof(r) << endl;
    cout << "Roll No:" << *r << '\n';
    cout << "CGPA" << *c << '\n';
}

