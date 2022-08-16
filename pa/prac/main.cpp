#include <iostream>

using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

struct Person{
    string name;
    struct Date dob;
};

void printPerson(struct Person p){
    cout << "Name: " << p.name << endl;
    cout << "Date of birth: " << p.dob.day << ' '<< p.dob.month << ' ' <<p.dob.year << endl;
}

int main(){
    int n;
    cout << "Enter no of people: ";
    cin >> n;
    struct Person people[n];
    for(int i=0;i <n; ++i){
        cout << "Enter name: ";
        cin >> people[i].name;
        cout << "Enter date of birth (d m y): ";
        cin >> people[i].dob.day;
        cin >> people[i].dob.month;
        cin >> people[i].dob.year;
    }
    for(int i=0; i<n; ++i){
        printPerson(people[i]);
    }
    struct Person eldest = people[0];
    struct Person youngest = people[0];
    for(int i=1; i<n; ++i){
        if(people[i].dob.year < eldest.dob.year){
            eldest = people[i]; 
        }
        else if(people[i].dob.month < eldest.dob.month){
            eldest = people[i]; 
        }
        else if(people[i].dob.day < eldest.dob.day){
            eldest = people[i]; 
        }
        if(people[i].dob.year > youngest.dob.year){
            youngest = people[i]; 
        }
        else if(people[i].dob.month > youngest.dob.month){
            youngest = people[i]; 
        }
        else if(people[i].dob.day > youngest.dob.day){
            youngest = people[i]; 
        }
    }
    cout << "Eldest is " << eldest.name << '\n';
    cout << "Youngest is " << youngest.name << '\n';
}
