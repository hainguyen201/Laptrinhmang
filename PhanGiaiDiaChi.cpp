﻿
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <winsock2.h>
#include<WS2tcpip.h>
#pragma comment(lib,"ws2_32")
using namespace std;
bool isIPString(char* s) {
	int i = 0;
	while (s[i] != '\n') {
		if()
	}
}
int main()
{
	WSAData wsa;
	//khởi tạo winsock
	int res= WSAStartup(MAKEWORD(2, 2), &wsa);
	if (res == 0) {
		addrinfo* info;
		SOCKADDR_IN addr;
		//lấy chuỗi kí tự từ bàn phím
		char s[100];
		cin.getline(s, 100);
		int ret = getaddrinfo(s, "http", NULL, &info);
		int err = WSAGetLastError();
		if (ret == 0) {
			while (info != NULL) {
				memcpy(&addr, info->ai_addr, info->ai_addrlen);
				printf("Dia chi ip: %s", inet_ntoa(addr.sin_addr));
				info = info->ai_next;
			}
		}
		else {
			printf("Loi khong phan giai duoc dia chi! Vui long kiem tra lai");
		}
	}
	
}