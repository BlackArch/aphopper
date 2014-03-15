#include "hopper.h"
int relink (char iface[6])
{
	FILE *cmd,*ssid_bad,*ssid_good;
	char command[50],bad[18],good[18],buf[]="any";
	int r=1,n=0,soc;
	struct iwreq wrq;

	printf("Changing Access Points....\n");
	strcpy(wrq.ifr_name,iface);
	wrq.u.essid.pointer=(caddr_t)buf;
	wrq.u.essid.length=sizeof(buf);
	wrq.u.essid.flags=0;
	soc=socket(AF_UNIX,SOCK_DGRAM,0);
	if(ioctl(soc,SIOCSIWESSID, &wrq)<0)
	{
		printf("Error setting ESSID on %s: %s\n",iface,strerror(errno));
		close(soc);
		exit(-1);
	}
	
	while (n<1)
	{
		n=getinfo(iface);
	}
	
	printf("Trying ESSID: %s\n",essid);
	ssid_bad=fopen("/root/.ssid_bad","r");
	if(ssid_bad==NULL)
	{
		printf("/root/.ssid_bad file does not exist...creating it.\n");
		cmd=popen("touch /root/.ssid_bad","r");
		pclose(cmd);
		return(2);
	}
	while ((fgets(bad,sizeof(bad),ssid_bad)) != 0)
	{
		if (strcmp(ap,bad)==0)
		{
			fclose(ssid_bad);
			printf("BSSID: %s is in the bad list.\n",ap);
			return(2);
		}
	}
	fclose(ssid_bad);
	ssid_good=fopen("/root/.ssid_good","r");
	if(ssid_good==NULL)
	{
		printf("/root/.ssid_good does not exist...creating it.\n");
		cmd=popen("touch /root/.ssid_good","r");
		pclose(cmd);
		return(2);
	}
	while ((fgets(good,sizeof(good),ssid_good)) != 0)
	{
		if (strcmp(ap,good)==0)
		{
			fclose(ssid_good);
			printf("BSSID: %s is in the good list.\n",ap);
			dhcp(iface);
			return(0);
		}
	}
	fclose(ssid_good);
	return(1);
}
