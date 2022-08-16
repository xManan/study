#include <iostream>

using namespace std;

#define MAX 4;

typedef struct {
    int keys[MAX-1];
    leafNode *leafPtrs[MAX];
    leafNode *parent;

} leafNode;

class Btree{
    public:
    leafNode *root;
    Btree(){
        root = NULL;
    }
    void insert(int n){
    }
};

int main(){

}
