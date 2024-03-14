/**
 ******************************************************************************
 * @file           : cs.c
 * @author         : wuxw
 * @brief          : None
 ******************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buf[1024], recv_buf[1024];

    // 创建套接字
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // 设置服务器地址结构体
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(&(server_addr.sin_zero), 8);

    // 连接服务器
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // 接收欢迎消息
    if (recv(sockfd, recv_buf, 1024, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("Server: %s\n", recv_buf);

    while (1) {
        // 输入消息
        printf("Client: ");
        fgets(send_buf, sizeof(send_buf), stdin);

        // 发送消息
        if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
            perror("send");
            exit(1);
        }

        // 接收消息
        if (recv(sockfd, recv_buf, 1024, 0) == -1) {
            perror("recv");
            exit(1);
        }
        printf("Server: %s\n", recv_buf);

        // 检查是否退出
        if (strcmp(send_buf, "exit\n") == 0) {
            break;
        }
    }

    // 关闭套接字
    close(sockfd);

    return 0;
}
