#ifndef SS_CPP
#define SS_CPP

#include <string>
#include <vector>

std::vector<std::string> splitStr(const std::string &s, const char c){
    std::string tmp = "";
    std::vector<std::string> res;
    
    for(int i=0; i<s.length(); ++i){
        if(s[i] != c){
            tmp += s[i];
        }
        else if(tmp.length() != 0){
            res.push_back(tmp);
            tmp = "";
        }
    }
    res.push_back(tmp);
    return res;
}

#endif
