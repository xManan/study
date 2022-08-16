#ifndef FSI_CPP
#define FSI_CPP

#include <iostream>
#include <string>
#include <fstream>
#include "numRepeatedWords.cpp"

class FileSystemInterface{
    public:
    virtual std::string readFile(const std::string &file)=0;
    virtual void writeFile(const std::string &file, const std::string &contents)=0;
};

class FileSystem: public FileSystemInterface{
    public:
    std::string readFile(const std::string &file){
        std::ifstream f(file); 
        if(!f){
            std::cerr << "Unable to read \"" << file << "\" file!\n";
            return "";
        }
        f.seekg(0, f.end);
        int len = f.tellg();
        f.seekg(0, f.beg);
        char buff[len];
        f.read(buff, len);
        f.close();
        return std::string(buff);
    }

    void writeFile(const std::string &file, const std::string &contents){
        std::ofstream fo(file);
        if(!fo){
            std::cerr << "Unable to write to \"" << file << "\" file!\n";
        }
        fo.write(contents.data(), contents.length());
        fo.close();
    }
};

#endif
