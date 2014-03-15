#include "hopper.h"

int internet(char iface[6])
{
	int fd, r;
	struct sockaddr_in server;
	struct hostent *he;
	char ip[]="www.google.com";

	printf("\nChecking for internet....");
	he=gethostbyname(ip);
	fd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_port=htons(80);
	server.sin_addr=*((struct in_addr *)he->h_addr);

	if(connect(fd,(struct sockaddr *)&server,sizeof(struct sockaddr))==-1)
	{
		printf("No.\n");
		printf("Couldn't get online\n");
		addbad(ap);
		close(fd);
		return(0);
	}
	printf("Yes.\n");
	printf("Everything looks good.\n");
	addgood(ap);
	close(fd);
	return (1);
}
