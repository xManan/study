#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        fprintf(stderr, "Port number not provided. Program terminated\n");
        exit(1);
    }

    int sockfd, newsockfd, portno;
    char buff[255];

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        error("Error opening socket!\n");
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("Binding failed\n");
    }

    listen(sockfd, 5);
    
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if(newsockfd < 0){
        error("Error on accept!\n");
    }

    while(1){
        bzero(buff, 255);
        int n = read(newsockfd, buff, 255);
        if(n < 0){
            error("Error on reading!\n");
        }
        printf("Client: %s\n", buff);
        bzero(buff, 255);
        fgets(buff, 255, stdin);

        n = write(newsockfd, buff, strlen(buff));
        if(n < 0){
            error("Error on writing!\n");
        }
        int i = strncmp("Bye", buff, 3);
        if(i == 0){
            break;
        }
    }
    close(newsockfd);
    close(sockfd);
    return 0;
}

