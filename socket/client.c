#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#include "../include/my_log.h"

#define BUFFER_SIZE 1024
static int sockfd;

static void sig_dispose(int sig)
{
    if(SIGINT == sig){
        close(sockfd);
        LOG_INFO("\tclose!");
        exit(0);
    }
}

void connect_server(void)
{
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        LOG_ERR("create socket fail");
        exit(-1);
    }

    bzero(&server_addr,sizeof(server_addr)); 
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    inet_pton(AF_INET, "10.200.20.19", &server_addr.sin_addr);

    int err_log = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(err_log != 0){
        LOG_ERR("connect fail");
        close(sockfd);
        exit(-1);
    }

    fd_set readset;
    int max_fd=8;
    struct timeval tv;

    char send_buf[BUFFER_SIZE] = "";
    char recv_buf[BUFFER_SIZE] = "";
    int server_sockfd = 3;
    long byte_num = 0;
    while(1){

        FD_ZERO(&readset);

        FD_SET(STDIN_FILENO, &readset);
        FD_SET(server_sockfd, &readset);
        tv.tv_sec = 1;
        tv.tv_usec = 0;


        int ret = select(max_fd + 1, &readset, NULL, NULL, &tv);  
        
        if(FD_ISSET(server_sockfd, &readset))  
        {  
            bzero(recv_buf , BUFFER_SIZE);
            byte_num = recv(server_sockfd, recv_buf, BUFFER_SIZE, 0); 
            if (byte_num > 0)  
            {  
                if(byte_num > BUFFER_SIZE)  
                {  
                    byte_num = BUFFER_SIZE;  
                }  
                recv_buf[byte_num] = '\0';  
                LOG_INFO("server:%s",recv_buf);
                // int i=0;
                // LOG_INFO("server:");
                // while(i < byte_num)
                // {
                //     LOG_INFO("%x\t",recv_buf[i]);
                //     i++;
                // }
            }
            else
            {
                LOG_INFO("the error message from server");  
            }
        }
        if(FD_ISSET(STDIN_FILENO, &readset))  
        {  
            fgets(send_buf,sizeof(send_buf),stdin);
            *(strchr(send_buf,'\n')) = '\0';
            send(sockfd, send_buf, strlen(send_buf), 0);
        }
    }
}

int main(int argc, char *argv[])
{
    LOG_INFO("client start...");

    signal(SIGINT,sig_dispose);

    connect_server();

    close(sockfd);
    return 0;
}