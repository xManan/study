#include <iostream>

void func1(int **x){
    int z = 10;
    *x = &z;
}

int *func2(){
    int z=11;
    return &z;
}

int main() {
    int *a;
    func1(&a);
    std::cout << *a << std::endl;
    int *b = func2();
    std::cout << *b << std::endl;
    return 0;
}

