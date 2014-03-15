#include "hopper.h"

// "Liberated" from iwcommon.c
char * convert_mac(unsigned char *ptr)
{
	static char buff[64];

	sprintf(buff, "%02X:%02X:%02X:%02X:%02X:%02X",
    	(ptr[0] & 0xFF), (ptr[1] & 0xFF), (ptr[2] & 0xFF),
	(ptr[3] & 0xFF), (ptr[4] & 0xFF), (ptr[5] & 0xFF));
	
	return(buff);
}
