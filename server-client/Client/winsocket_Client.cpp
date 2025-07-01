#include <iostream>
#include<winsock2.h>
#pragma warning(disable:4996)
using namespace std;

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup failed with error: " << WSAGetLastError();
        return FALSE;
    }

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(80);
    client.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    Sleep(5000);

    connect(sock, (struct sockaddr *)&client, sizeof(struct sockaddr));

    for (;;) {
        char buffer[1024];
        cout << "Please enter a string: ";
        cin.getline(buffer, 1024);

        send(sock, buffer, sizeof(buffer), 0);

        char buf[1024];
        recv(sock, buf, sizeof(buf), 0);
        cout << buf << endl;
    }
    closesocket(sock);
}