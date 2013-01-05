
#include <stdio.h>
#include "billigtest.h"

void sjekk_sann (int testbool, const char *testnavn)
{
	if (testbool)
		printf("%s:\tpass\n", testnavn);
	else
		printf("%s:\tfeil\n", testnavn);
}

void sjekk_usann (int testbool, const char *testnavn)
{
	if (!testbool)
		printf("%s:\tpass\n", testnavn);
	else
		printf("%s:\tfeil\n", testnavn);
}

void printbin (int bin, int size)
{
	int bit, mask;

	for (bit=0; bit<size; bit++)
	{
		mask = (1<<(size-1-bit));

		if (bin & mask)
			printf("1");
		else
			printf("0");
	}
}
