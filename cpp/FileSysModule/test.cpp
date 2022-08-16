#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include "splitStr.cpp"
#include "numRepeatedWords.cpp"
#include "FileSystemInterface.cpp"

int readFileCount = 0;
int writeFileCount = 0;

class FileSystemTest: public FileSystemInterface{
    public:
    std::string readFile(const std::string &file){
        ++readFileCount;
        if(file != "inp_file"){
            std::cerr << "Expected 'inp_file' but got " << file << "!\n";
            exit(EXIT_FAILURE);
        }
        return "some content some !";
    }

    void writeFile(const std::string &file, const std::string &contents){
        ++writeFileCount;
        if(file != "out_file"){
            std::cerr << "Expected 'inp_file' but got " << file << "!\n";
            exit(EXIT_FAILURE);
        }
        if(contents != "1"){
            std::cerr << "Expected content '1' but got " << contents << "!\n";
            exit(EXIT_FAILURE);
        }
    }
};

void run(FileSystemInterface &fs, const std::string &inp_file, const std::string &out_file){
    std::string str = fs.readFile(inp_file);
    fs.writeFile(out_file, std::to_string(numRepeatedWords(str)));
}

int main(int argc, char *argv[]){
    std::string inp_file = "inp_file";
    std::string out_file = "out_file";

    FileSystemTest fs;

    run(fs, inp_file, out_file);

    if(readFileCount != 1){
        std::cerr << "Expected readFileCount 1 but got " << readFileCount << "!\n";
        exit(EXIT_FAILURE);
    }

    if(writeFileCount != 1){
        std::cerr << "Expected writeFileCount 1 but got " << writeFileCount << "!\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Test Passed successfully!\n";
}
