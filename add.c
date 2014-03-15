#include "hopper.h"
void addbad(char ap[18])
{
	FILE *bad;

	bad=fopen("/root/.ssid_bad","a");
	fprintf(bad,"%s\n",ap);
	fclose(bad);
}

void addgood(char ap[18])
{
	FILE *good;

	good=fopen("/root/.ssid_good","a");
	fprintf(good,"%s\n",ap);
	fclose(good);
}
