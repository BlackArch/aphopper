#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <linux/wireless.h>

int relink(char iface[6]);
int dhcp(char iface[6]);
void addbad(char ap[18]);
void addgood(char ap[18]);
int internet(char iface[6]);
int getinfo(char iface[6]);
char * convert_mac(unsigned char *ptr);

char essid[IW_ESSID_MAX_SIZE+1];
char ap[18];
