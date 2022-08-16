#include <stdio.h>
#include <string.h>

int main(){
    for(int i=1; i<=100; ++i){
        char out[8] = "";
        if(i%3 == 0)
            strcat(out, "Fizz");
        if(i%5 == 0)
            strcat(out, "Buzz");
        if(strlen(out) == 0)
            printf("%d\n",i);
        else
            printf("%s\n", out);
    }
}
