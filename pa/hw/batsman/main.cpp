#include <iostream>
#include <string>
#include "Batsman.h"

using namespace std;

enum OPTIONS {
    ADD=1,
    AVG,
    DISPLAY
};

int searchBatsman(Batsman b[], int size, string name){
    for(int i=0; i<size; ++i){
        if(b[i].name() == name) return i;
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
            case ADD:{
                Batsman tmp;
                cin >> tmp;
                batsman[currCount++] = tmp;
                break;
            }
            case AVG:{
                string query;
                cout << "Enter name of a player to see his avg: ";
                cin.ignore();
                getline(cin, query);
                int index = searchBatsman(batsman, currCount, query);
                break;
            }
            case DISPLAY:
                for(int i=0; i<currCount; ++i){
                    batsman[i].info();
                }
                break;
            default:
                cout << "NOT A VALID OPTION\n";
        }
    }
}
