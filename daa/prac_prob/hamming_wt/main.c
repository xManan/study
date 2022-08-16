#include <stdio.h>
#include <stdint.h>

const uint64_t m1  = 0x5555555555555555;
const uint64_t m2  = 0x3333333333333333;
const uint64_t m4  = 0x0f0f0f0f0f0f0f0f;
const uint64_t m8  = 0x00ff00ff00ff00ff;
const uint64_t m16 = 0x0000ffff0000ffff;
const uint64_t m32 = 0x00000000ffffffff;

int popcount64a(uint64_t x){
    x = (x & m1 ) + ((x >> 1) & m1 );
    x = (x & m2 ) + ((x >> 2) & m2 );
    x = (x & m4 ) + ((x >> 4) & m4 );
    x = (x & m8 ) + ((x >> 8) & m8 );
    x = (x & m16) + ((x >> 16) & m16);
    x = (x & m32) + ((x >> 32) & m32);
    return x;
}

int popcount64b(uint64_t x){
    x -= (x >> 1) & m1;
    x =  (x & m2) + ((x >> 2) & m2);
    x =  (x + (x >> 4)) & m4;
    x += x >> 8;
    x += x >> 16;
    x += x >> 32;
    return x & 0xff;
}

int main(){
    uint64_t a = 8392776545678453;
    printf("%d\n", popcount64a(a));
    printf("%d\n", popcount64b(a));
}
