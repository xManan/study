#include <iostream>

using namespace std;

class Student{
    string name;
    int age;
    public:
    Student(){
        cout << "Defautl Constructor called\n";
    }
    Student(string name, int age){
        this->name = name;
        this->age = age;
        cout << "overloaded Constructor with 2 args\n";
    }
    void display(){
        cout << "Name: " << name << '\n' << "Age: " << age << '\n';
    }
    void *operator new(size_t size){
        cout << "overloading new operator\n";
        void *p = ::operator new(size);
        return p;
    }
    void operator delete(void *p){
        cout << "overloading delete operator\n";
        free(p);
    }
};

int main(){
    Student *p = new Student("cpp", 4);
    p->display();
    delete p;
}
