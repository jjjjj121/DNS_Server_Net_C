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

	//ã������ ������ �ּ�
	hostent* infos = gethostbyname("naver.com");

	//�����ϰ� �ִ� ����?�� �ִ°�?
	for (int i = 0; infos->h_aliases[i]; ++i)
	{
		printf("alias %s\n", infos->h_aliases[i]);
	}

	//�ش� �����ΰ� ����� IP�ּ�
	for (int i = 0; infos->h_addr_list[i]; ++i)
	{
		printf("ip %s\n", inet_ntoa(*(IN_ADDR*)infos->h_addr_list[i]));
	}

	//IP�ּ� Ÿ���� �����ΰ�?
	printf("address type %s", infos->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6");



	//223.130.195.95
	//ip �־��ָ� ������ �������� �Լ�
	//gethostbyaddr



	WSACleanup();


	return 0;
}