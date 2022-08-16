#ifndef NRW_CPP
#define NRW_CPP

#include <string>
#include <set>
#include "splitStr.cpp"

int numRepeatedWords(const std::string &content){
    std::vector<std::string> lines = splitStr(content, '\n');
    std::vector<std::string> words;
    for(int i=0; i<lines.size(); ++i){
        std::vector<std::string> tmp = splitStr(lines[i], ' ');
        words.insert(words.begin(), tmp.begin(), tmp.end());
    }
    std::set<std::string> seen, repeatedWords;
    for(std::string word: words){
        if(seen.find(word) != seen.end()){
            repeatedWords.insert(word);
        }
        seen.insert(word);
    }
    return repeatedWords.size();
}

#endif
