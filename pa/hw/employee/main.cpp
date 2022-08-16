#include <iostream>

using namespace std;

class Performance{
protected:
    int punctual_;
    int on_time_submissions_;
    int task_submission_rate_;
public:
    Performance(int punc=0, int ots=0, int tsr=0):
    punctual_(punc),
    on_time_submissions_(ots),
    task_submission_rate_(tsr)
    {}

    int calcTotal(){
        return punctual_ + on_time_submissions_ + task_submission_rate_;
    }
};

class Employee: public Performance{
    int uid_;
    string name_;
    int years_of_experience_;
public:
    Employee(int uid=0, string name="", int yeo=0):
    uid_(uid),
    name_(name),
    years_of_experience_(yeo)
    {}

    Employee(int uid=0, string name="", int yeo=0, int punc=0, int ots=0, int tsr=0):
    Performance(punc, ots, tsr),
    uid_(uid),
    name_(name),
    years_of_experience_(yeo)
    {}

    void input(){
        cout << "Enter employee id: ";
        cin >> uid_;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name_);
        cout << "Enter years of experience: ";
        cin >> years_of_experience_;
        cout << "Enter punctuality (out of 100): ";
        cin >> punctual_;
        cout << "Enter on time submissions (out of 100): ";
        cin >> on_time_submissions_;
        cout << "Enter task submission rate (out of 100): ";
        cin >> task_submission_rate_;
    }

    void display(){
        cout << "employee id: " << uid_ << '\n';
        cout << "employee name: " << name_ << '\n';
        cout << "years of experience: " << years_of_experience_ << '\n';
        cout << "punctuality (out of 100): " << punctual_ << '\n';
        cout << "on time submissions (out of 100): " << on_time_submissions_ << '\n';
        cout << "task submission rate (out of 100): " << task_submission_rate_ << '\n';
    }
};

int main(){
    Employee e1(1, "Manan", 10, 69, 80, 98); 
    e1.display();
    cout << e1.calcTotal() << '\n';
    
}
