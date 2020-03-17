
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <winsock2.h>
#include<WS2tcpip.h>
#pragma comment(lib,"ws2_32")
using namespace std;
//hàm kiểm tra kí tự a
bool isCharacter(char a) {
	return a == '.' || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || a == '-';
}
//hàm kiểm tra chuỗi hợp lệ
bool isIPString(char* s) {
	int i = 0;
	while (s[i] != '\0') {
		if(!isCharacter(s[i])) return false;
			i++;
	}
	return true;
}

int main()
{
	//khởi tạo winsock
	WSAData wsa;
	int res= WSAStartup(MAKEWORD(2, 2), &wsa);
	if (res == 0) {
		addrinfo* info;
		SOCKADDR_IN addr;
		//lấy chuỗi kí tự từ bàn phím
		char s[100];
		cin.getline(s, 100);
		//kiểm tra chuỗi ký tự
		if (!isIPString(s)) {
			printf("Ten mien chua ky tu khong hop le");
			return 1;
		}
		//phân giải địa chỉ
		int ret = getaddrinfo(s, "http", NULL, &info);
		int err = WSAGetLastError();
		//Ghi địa chỉ IP đã phân giải ra màn hình
		if (ret == 0) {
			//duyệt từng địa chỉ IP
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