#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    pid_t pid = fork();
    if(pid < 0){
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if (pid == 0) {
        execlp("/bin/ls", "/dev",NULL);
    }
    else{
        wait(NULL);
        fprintf(stdout, "child complete");
    }
}

