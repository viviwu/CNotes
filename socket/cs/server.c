/**
 ******************************************************************************
 * @file           : server.c
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
#define MAX_CLIENTS 10

int main() {
    int sockfd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t sin_size;
    char recv_buf[1024];

    // 创建套接字
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // 设置服务器地址结构体
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8);

    // 绑定端口
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    // 监听端口
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }
    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        sin_size = sizeof(struct sockaddr_in);

        // 接受客户端连接
        if ((new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size)) == -1) {
            perror("accept");
            continue;
        }
        printf("Server: Got connection from %s\n", inet_ntoa(client_addr.sin_addr));

        // 发送欢迎消息
        char welcome_msg[] = "Welcome to the chat server!\n";
        if (send(new_fd, welcome_msg, strlen(welcome_msg), 0) == -1) {
            perror("send");
            close(new_fd);
            continue;
        }

        // 处理消息
        while (1) {
            // 接收消息
            if (recv(new_fd, recv_buf, 1024, 0) == -1) {
                perror("recv");
                break;
            }
            if (strlen(recv_buf) == 0) {
                break;
            }
            printf("Client %s: %s\n", inet_ntoa(client_addr.sin_addr), recv_buf);

            // 广播消息给所有客户端
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (i != new_fd && send(i, recv_buf, strlen(recv_buf), 0) == -1) {
                    perror("send");
                }
            }

            // 检查是否退出
            if (strcmp(recv_buf, "exit\n") == 0) {
                break;
            }

            memset(recv_buf, 0, sizeof(recv_buf));
        }

        // 关闭连接
        printf("Client %s disconnected.\n", inet_ntoa(client_addr.sin_addr));
        close(new_fd);
    }

    // 关闭套接字
    close(sockfd);

    return 0;
}
