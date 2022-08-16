#include <iostream>
#include <string>

using namespace std;

class Batsman{
    // data members
    string name_;
    int innings_, notout_, runs_;

    public:

    // constructors
    Batsman(string name="", int innings=0, int notout=0, int runs=0);

    // getters
    string name();
    int innings();
    int notout();
    int runs();

    // setters
    void name(string name_);
    void innings(int innings_);
    void notout(int notout_);
    void runs(int runs_);
    
    // io operator overloading
    friend istream& operator>>(istream &inp, Batsman &b);
    friend ostream& operator<<(ostream &out, const Batsman &b);

    // members functions
    float average();
    void info();
};

// overloading constructor definition
Batsman::Batsman(string name, int innings, int notout, int runs): 
    name_(name),
    innings_(innings),
    notout_(notout),
    runs_(runs)
{}

// function to get name of the player
string Batsman::name(){
    return name_;
}

// function to get innings of the player
int Batsman::innings(){
    return innings_;
}

// function to get notout of the player
int Batsman::notout(){
    return notout_;
}

// function to get runs of the player
int Batsman::runs(){
    return runs_;
}

// function to set name of the player
void Batsman::name(string name){
    name_ = name;
}

// function to set innings of the player
void Batsman::innings(int innings){
    innings_ = innings;
}

// function to set notout of the player
void Batsman::notout(int notout){
    notout_ = notout;
}

// function to set runs of the player
void Batsman::runs(int runs){
    runs_ = runs;
}

// input operator overloading to take input as "cin >> Batsman"
istream& operator>>(istream &inp, Batsman &b){
    cout << "Enter player name: ";
    inp.ignore();
    getline(inp, b.name_);
    cout << "Enter player's innings: ";
    inp >> b.innings_;
    cout << "Enter player's notout: ";
    inp >> b.notout_;
    cout << "Enter player's runs: ";
    inp >> b.runs_;
    return inp;
}

// ouput operator overloading to print batsman object as "cout << Batsman"
ostream& operator<<(ostream &out, const Batsman &b){
    out << "Name: " << b.name_ << '\n'
        << "Innings: " << b.innings_ << '\n'
        << "Notout: " << b.notout_ << '\n'
        << "Runs: " << b.runs_ << '\n';
    return out;
}

// function to calculate average of the player
float Batsman::average(){
    return float(runs_)/float(innings_ - notout_);
}

// function to display information of the player
void Batsman::info(){
    cout << "BatsMan: " << name_ 
        << " played: " << innings_ 
        << " with runs: " << runs_ 
        << " and not out for: " << notout_ << '\n';
}

// function to search a player and return its index. return -1 if player not found
int searchBatsman(Batsman b[], int size, string name){
    for(int i=0; i<size; ++i){
        if(b[i].name() == name) 
            return i;
    }
    return -1;
}

int main(){
    int tmp;
    cout << "How many batsman ? ";
    cin >> tmp;
    const int batsmanCount = tmp;
    int currCount = 0;
    Batsman batsman[batsmanCount];
    while (1) {
        int opt = -1;
        cout << "1. input\n2.search\n3.display\n";
        cin >> opt;
        switch(opt){
            case 1:{
                Batsman tmp;
                cin >> tmp;
                batsman[currCount++] = tmp;
                break;
            }
            case 2:{
                string query;
                cout << "Enter name of a player to see his avg: ";
                cin.ignore();
                getline(cin, query);
                int index = searchBatsman(batsman, currCount, query);
                if(index!=-1) cout << batsman[index].average() << '\n';
                else cout << "Player not found!\n";
                break;
            }
            case 3:
                for(int i=0; i<currCount; ++i){
                    batsman[i].info();
                }
                break;
            default:
                cout << "NOT A VALID OPTION\n";
        }
    }
}
