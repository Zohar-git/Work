#define WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN

#include<sys/socket.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

int main(void)
{
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        printf("WSAStartup failed with error: %d\n", result);
        return 1;
    }

    char *message = "What up sucker";
    int socket_server = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_server == INVALID_SOCKET)
    {
        printf("Socket creation failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    result = bind(socket_server, (struct sockaddr *)&server_address, sizeof(server_address));
    if (result == SOCKET_ERROR)
    {
        printf("Bind failed with error: %d\n", WSAGetLastError());
        closesocket(socket_server);
        WSACleanup();
        return 1;
    }

    result = listen(socket_server, 2);
    if (result == SOCKET_ERROR)
    {
        printf("Listen failed with error: %d\n", WSAGetLastError());
        closesocket(socket_server);
        WSACleanup();
        return 1;
    }

    printf("Waiting for client connection...\n");

    int socket_client = accept(socket_server, NULL, NULL);
    if (socket_client == INVALID_SOCKET)
    {
        printf("Accept failed with error: %d\n", WSAGetLastError());
        closesocket(socket_server);
        WSACleanup();
        return 1;
    }

    printf("Client connected. Sending message...\n");
    result = send(socket_client, message, strlen(message), 0);
    if (result == SOCKET_ERROR)
    {
        printf("Send failed with error: %d\n", WSAGetLastError());
        closesocket(socket_client);
        closesocket(socket_server);
        WSACleanup();
        return 1;
    }

    printf("Message sent. Closing sockets...\n");

    closesocket(socket_client);
    closesocket(socket_server);
    WSACleanup();

    return 0;
}
