#include <iostream>
 using namespace std;


int operation(int x, int y, int (*func)(int,int)){
    int g = (*func)(x,y);
    return g;
}
int add(int x, int y){
    return x+y;
}

int operation(int x, int y,int z, int (*func)(int,int,int)){
    int g = (*func)(x,y,z);
    return g;
}
int add(int x, int y, int z){
    return x+y+z;
}

int main(){
    int (*func)(int,int) = add;
    int(*funcArr[])(int,int) = {add};
    cout << operation(5, 5, 6, add);
}
