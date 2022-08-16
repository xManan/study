#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include "splitStr.cpp"
#include "numRepeatedWords.cpp"
#include "FileSystemInterface.cpp"

void run(FileSystemInterface &fs, const std::string &inp_file, const std::string &out_file){
    std::string str = fs.readFile(inp_file);
    fs.writeFile(out_file, std::to_string(numRepeatedWords(str)));
}

int main(int argc, char *argv[]){
    if(argc != 3){
        std::cerr << "Wrong number of arguments!\n";
        return EXIT_FAILURE;
    }

    std::string inp_file = argv[1];
    std::string out_file = argv[2];

    FileSystem fs;

    run(fs, inp_file, out_file);
}
