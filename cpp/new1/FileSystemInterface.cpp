#include <fstream>
#include <string>

class FileSystemInterface{
    public:
    std::string readFile(const std::string &file);
    void writeFile(const std::string &file, const std::string &contents);
};

class realFileSystemModule: public FileSystemInterface{
    public: 
    std::string readFile(const std::string &file){
        std::ifstream f(file);
        if(!f) return "";
        f.seekg(0,f.end);
        int len = f.tellg();
        f.seekg(0,f.beg);
        char buffer[len];
        f.read(buffer,len);
        f.close();
        return buffer; 
    }
    
    void writeFile(const std::string &file, const std::string &contents){
        std::ofstream f(file);
        f.write(contents.data(), contents.length());
    }
};

