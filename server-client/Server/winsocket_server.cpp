#include <charconv>
#include <cmath>
#include <iostream>
#include <vector>
#include <winsock2.h>
#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")
using namespace std;

string Ceaser(string text, int shift) {
    string result;
    for (int i = 0; i < static_cast<int>(text.length()); i++) {
        if ((int)text[i] >= 97 && (int)text[i] <= 122) {
            result += static_cast<char>(((int)text[i]-97+shift)%26+97);
        }
        else if ((int)text[i] >= 65 && (int)text[i] <= 90) {
            result += static_cast<char>(((int)text[i]-65+shift)%26+65);
        }
        else{
            result += text[i];
        }
    }
    return result;
}
string Atbash(string text) {
    string result;
    for (int i = 0; i < static_cast<int>(text.length()); i++) {
        if ((int)text[i] >= 97 && (int)text[i] <= 122) {
            result += static_cast<char>(26 - ((int)text[i]-97) - 1 +97);
        }
        else if ((int)text[i] >= 65 && (int)text[i] <= 90) {
            result += static_cast<char>(26 - ((int)text[i]-65) - 1 + 65);
        }
        else{
            result += text[i];
        }
    }
    return result;
}
string Affine(string text, int key1, int key2) {
    if (key2 % 2 == 0 && key2 % 13 == 0) {
        cout << "key2 cannot have a common divisor of 26";
        return "";
    }
    string result;
    for (int i = 0; i < static_cast<int>(text.length()); i++) {
        if ((int)text[i] >= 97 && (int)text[i] <= 122) {
            result += static_cast<char>((((int)text[i]-97) * key2 + key1)%26 + 97);
        }
        else if ((int)text[i] >= 65 && (int)text[i] <= 90) {
            result += static_cast<char>((((int)text[i]-65) * key2 + key1)%26 + 65);
        }
        else{
            result += text[i];
        }
    }
    return result;
}

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup failed. Error: " << WSAGetLastError();
        return FALSE;
    }

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(80);

    bind(sock, (LPSOCKADDR)&server, sizeof(server));

    listen(sock, 100);

    sockaddr_in client{};
    int clientSize = sizeof(client);
    SOCKET clientSocket = accept(sock, (struct sockaddr*) & client, &clientSize);
    cout << "Client Connected" << endl;
    for (;;) {
        char recvbuf[1024];

        recv(clientSocket, recvbuf, sizeof(recvbuf), 0);
        cout << "Message from client: " << recvbuf << '\0' << endl;

        if (strcmp(recvbuf, "Bye") == 0) {
            break;
        }
        char sendbuf[1024];

        string message = Ceaser(recvbuf, 1);

        for (int i = 0; i < message.length(); i++) {
            sendbuf[i] = message[i];
        }


        Sleep(1000);

        send(clientSocket, sendbuf, sizeof(sendbuf), 0);

        memset(sendbuf, 0,1024);
    }
    closesocket(clientSocket);
}
