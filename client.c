/*
 * client.c
 *
 *  Created on: 19-Mar-2017
 *      Author: rp
 	this is client for IPv6
 */
#include "sock.h"

int main(int argc,char *argv[])
{
	if(argc<3)
	{
		printf("usage : ./server <Port Number> <>IP Address\n");
		return 0;
	}
	int sfd;
	char s[25];
#if H_IPV4
	sfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in v;
	v.sin_family = AF_INET;
	v.sin_port = htons(atoi(argv[1]));
	v.sin_addr.s_addr = inet_addr(ADDR_4);
	socklen_t len = sizeof(v);
#elif H_IPV6
	sfd = socket(AF_INET6,SOCK_STREAM,0);
	struct sockaddr_in6 v;
	v.sin6_family = AF_INET6;
	v.sin6_port = htons(atoi(argv[1]));
	v.sin6_flowinfo = 0;
	v.sin6_scope_id = if_nametoindex(argv[3]);
	inet_pton(AF_INET6,argv[2],&v.sin6_addr.__in6_u);
	socklen_t len = sizeof(v);
#endif
	connect(sfd,(struct sockaddr *)&v,len);
	printf("Enter Data\n");
	scanf("%s",s);
	write(sfd,s,strlen(s)+1);
	return 0;
}
