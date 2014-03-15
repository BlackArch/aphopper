#include "hopper.h"

int getinfo(char iface[6])
{
	int fr;
	struct iwreq wrq;
	char buf[IW_ESSID_MAX_SIZE+1];

	memset(buf,0,sizeof(buf));
	memset(&wrq,0,sizeof(wrq));	

	fr=socket(AF_UNIX,SOCK_DGRAM,0);
	strcpy(wrq.ifr_name,iface);
	wrq.u.essid.pointer = (caddr_t)buf;
	wrq.u.essid.length=0;
	wrq.u.essid.flags=0;
	if(ioctl(fr,SIOCGIWESSID,&wrq)<0)
	{
		close(fr);
		printf("Error getting ESSID from %s: %s\n",iface,strerror(errno));
		return 0;
	}
	if (buf[0] == '\0')
	{		
		close(fr);
		return 0;
	}
	strncpy(essid,buf,IW_ESSID_MAX_SIZE);
	memset(buf,0,sizeof(buf));
	if(ioctl(fr, SIOCGIWAP, &wrq)<0)
	{
		close(fr);
		printf("Error getting BSSID from %s\n",iface);
		return 0;
	}

	if (wrq.u.ap_addr.sa_data[0] == 0x44)
	{
		close(fr);
		return 0;
	}
	strcpy(ap,convert_mac((unsigned char*)&wrq.u.ap_addr.sa_data));
	return 1;
}
