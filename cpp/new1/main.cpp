#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include "FileSystemInterface.cpp"

using namespace std;

vector<string> splitString(const string &s, char c){
    string buff = "";
    vector<string> v;
    for(int i=0; i<s.length(); ++i){
        if(s[i] != c){
            buff += s[i];
        }
        else if(s[i] == c && buff != ""){
            v.push_back(buff);
            buff = "";
        }
    }
    if(buff != "") v.push_back(buff);
    return v;
}

int repeatedNum(const string &str){
    vector<string> v = splitString(str, ' ');
    set<string> seen, repeatedWords;
    for(auto s:v){
        if(seen.find(s) != seen.end()){
            repeatedWords.insert(s);
        }
        seen.insert(s);
    }
    return repeatedWords.size();
}

void run(FileSystemInterface *fileSys, string inp_file, string out_file){
    string buffer = fileSys->readFile(inp_file);
    int n_size = 2;
    char res[n_size];
    sprintf(res, "%d", repeatedNum(buffer));
    fileSys->writeFile(out_file, res);
}

int main(int argc, char *argv[]){
    if(argc != 3){
        cerr << "wrong number of arguments!\n";
        return 1;
    }
    string input_file = argv[1];
    string output_file = argv[2];
    run(new realFileSystemModule(), input_file, output_file);
}

