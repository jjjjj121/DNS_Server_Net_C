#define _WINSOCK_DEPRECATED_NO_WARNINGS


#include <stdio.h>
#include <WinSock2.h>
#include <iostream>
#include <string>
#pragma comment (lib, "ws2_32.lib")

using namespace std;

int main()
{

	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);


	hostent* infos = gethostbyname("Umamusume.com");

	for (int i = 0; infos->h_aliases[i]; ++i)
	{
		printf("alias %s\n", infos->h_aliases[i]);
	}

	for (int i = 0; infos->h_addr_list[i]; ++i)
	{
		printf("ip %s\n", inet_ntoa(*(IN_ADDR*)infos->h_addr_list[i]));
	}

	printf("address type %s", infos->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6");



	//223.130.195.95
	//ip 넣어주면 정보를 가져오는 함수
	//gethostbyaddr



	WSACleanup();


	return 0;
}