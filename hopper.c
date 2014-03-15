#include "hopper.h"
main (int argc, char **argv)
{
	FILE *cmd, *proc;
	char link[4],iface[6];
	int i, n, r=3, linkint;

	printf("AP Hopper - by Strubenator\n");
	if (argc != 2)
	{
		printf("Usage: %s <interface>\n",argv[0]);
		exit(-1);
	}

	strncpy(iface,argv[1],sizeof(iface));
	printf("Running on interface %s\n",iface);

	while (i)
	{
		proc=fopen("/proc/net/wireless","r");
		for (n=1; n<59; n++)
		{
			fgets(link,sizeof(link),proc);
		}
		linkint = atoi(link);
		printf("%s\r",link);
		switch (r)	
		{
		case 0: if (linkint < 11)
			{
				printf("Loosing Link\n");
				r=relink(iface);
			}
			break;

		case 2: printf("BSSID: %s is bad\n",ap);
			r=relink(iface);
			break;

		case 1: if (linkint > 10)
			{	
				printf("done.\n");
				r=dhcp(iface);
			}
			break;

		case 3: r=relink(iface);
			break;
		}
		fclose(proc);
	}

}
