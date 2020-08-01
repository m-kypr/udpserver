#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <chrono>

int main(int argc, char* argv[])
{
	int port;
	if (argc > 1) { 
		port = atoi(argv[1]); 
	} else {
		printf("Usage: UDPServer <port>\n");
		exit(1);
	}
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in serv, cli;
	serv.sin_family = AF_INET;
	serv.sin_port = htons(port);
	serv.sin_addr.s_addr = INADDR_ANY;
	char buffer[256];
	socklen_t l = sizeof(cli);
	printf("Listening to port %i\n", port);
	bind(sockfd, (struct sockaddr*) &serv, sizeof(serv));
	while (true) {
		recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &cli, &l);
		char ip_buf[INET_ADDRSTRLEN];
		std::cout << "???" << "\n";
		inet_ntop(AF_INET, &cli.sin_addr, ip_buf, INET_ADDRSTRLEN);
		const auto now = std::chrono::system_clock::now();
		//std::time_t now_time = std::chrono::system_clock::to_time_t(now);
		//std::cout<<
		//	std::ctime(&now_time)<<"["<<
		//	ip_buf<<"]: "<<
		//	buffer<<std::endl;
		if (strcmp("start", buffer) == 0) {
			printf("[server] Starting the script...\n");
		}
		memset(buffer, 0, 256);
	}
	return 0;
}
