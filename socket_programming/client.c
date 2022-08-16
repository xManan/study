#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    if (argc < 3) {
        fprintf(stderr, "usage %s hostnam port\n", argv[0]);
        exit(1);
    }

    int sockfd, portno, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buff[255];

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        error("Error opening socket\n");
    }
    server = gethostbyname(argv[1]);
    if(server == NULL){
        error("Error, no such host\n");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("Connection failed!\n");
    }
    while(1){
        bzero(buff, 255);
        fgets(buff, 255, stdin);
        n = write(sockfd, buff, strlen(buff));
        if(n < 0){
            error("Error on writing\n");
        }
        bzero(buff, 255);
        n = read(sockfd, buff, 255);
        if(n < 0){
            error("Error on reading\n");
        }
        printf("Server: %s\n", buff);
        int i = strncmp("Bye", buff, 3);
        if(i == 0){
            break;
        }
    }
    close(sockfd);
    return 0;
}
