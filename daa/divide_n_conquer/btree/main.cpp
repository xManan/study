#include <iostream>

using namespace std;

#define ORDER 3

typedef struct node{
    int keys[ORDER-1];
    node *children[ORDER];
    node *parent;
} node;

int main(){
    node n;
    node n1;
    n.keys[0] = 10;
    n1.keys[0] = 14;
    n.children[0] = &n1;
    cout << n.keys[0] << " " << n.children[0]->keys[0];
}
