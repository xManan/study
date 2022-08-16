#ifndef BATSMAN_H
#define BATSMAN_H

#include <string>

class Batsman{
    // data members
    std::string name_;
    int innings_, notout_, runs_;

    public:

    // constructors
    Batsman(std::string name="", int innings=0, int notout=0, int runs=0);

    // getters
    std::string name();
    int innings();
    int notout();
    int runs();

    // setters
    void name(std::string name_);
    void innings(int innings_);
    void notout(int notout_);
    void runs(int runs_);
    
    // io operator overloading
    friend std::istream& operator>>(std::istream &inp, Batsman &b);
    friend std::ostream& operator<<(std::ostream &out, const Batsman &b);

    // members functions
    float average();
    void info();
};

#endif
