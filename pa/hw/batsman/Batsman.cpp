#include <iostream>
#include <string>
#include "Batsman.h"

Batsman::Batsman(std::string name, int innings, int notout, int runs): 
    name_(name),
    innings_(innings),
    notout_(notout),
    runs_(runs)
{}

std::string Batsman::name(){
    return name_;
}

int Batsman::innings(){
    return innings_;
}

int Batsman::notout(){
    return notout_;
}

int Batsman::runs(){
    return runs_;
}

void Batsman::name(std::string name){
    name_ = name;
}

void Batsman::innings(int innings){
    innings_ = innings;
}

void Batsman::notout(int notout){
    notout_ = notout;
}

void Batsman::runs(int runs){
    runs_ = runs;
}

std::istream& operator>>(std::istream &inp, Batsman &b){
    std::cout << "Enter player name: ";
    inp.ignore();
    std::getline(inp, b.name_);
    std::cout << "Enter player's innings: ";
    inp >> b.innings_;
    std::cout << "Enter player's notout: ";
    inp >> b.notout_;
    std::cout << "Enter player's runs: ";
    inp >> b.runs_;
    return inp;
}

std::ostream& operator<<(std::ostream &out, const Batsman &b){
    out << "Name: " << b.name_ << '\n'
        << "Innings: " << b.innings_ << '\n'
        << "Notout: " << b.notout_ << '\n'
        << "Runs: " << b.runs_ << '\n';
    return out;
}

float Batsman::average(){
    return float(runs_)/float(innings_ - notout_);
}

void Batsman::info(){
    std::cout << "BatsMan: " << name_ 
        << " played: " << innings_ 
        << " with runs: " << runs_ 
        << " and not out for: " << notout_ << '\n';
}
