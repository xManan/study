#include <iostream>

using namespace std;

class Subject{

};

class Student{
    int uid;
    string name;
    static int numSubjects;
    static int nextUid;
    Subject *subjects;
public:
    Student(int uid=nextUid++, string name=""){
        this->uid = uid;
        this->name = name;
    }
    int calcTotal(){
        return 0;
    }
    void display(){

    }


};

int main(){

}
