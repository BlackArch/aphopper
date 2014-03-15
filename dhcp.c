#include "hopper.h"
int dhcp(char iface[6])
{
	int r=0;
	char command[50],bad[18];
	FILE *cmd,*ssid;

	printf("\nTrying to automatically configure %s on BSSID: %s...",iface,ap);
	snprintf(command,50,"/sbin/dhcpcd -t 10 -n %s",iface);
	cmd=popen(command,"r");
	r=pclose(cmd);
	if (r==1)
	{
		printf("Error\nNo DHCP on this Network.\n");
		addbad(ap);
		return(2);
	}
	printf("done.\n");
	r=internet(iface);
	if(r==0)
	{	
		return(2);
	}
	return (0);
}
