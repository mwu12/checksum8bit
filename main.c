#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char LibGzB64_CalcChecksum(unsigned char* Data, int BuffSize)
{
	unsigned char ChecksumValue=0;
	int i;

	for(i=0;i<BuffSize;i++)
	{
		ChecksumValue += Data[i];
	}

	ChecksumValue = (0xFF - (ChecksumValue % 0x100)) +1;	
	return ChecksumValue;
}

int main(int argc, char *argv[])
{
    int i;
	unsigned char* indata;
    if (argc < 2)
    {
        printf("Usage: %s arg1 arg2 ...\n", argv[0]);
        return 1;
    }
    indata = (unsigned char*) malloc( (argc - 1) * sizeof(char));
    for (i=1; i<argc; i++)
    {
        printf("argv[%d] %s\n", i, argv[i]);
        indata[i-1] = (unsigned char)argv[i][0];
    }

    printf("checksum 0x%X\n", (unsigned int) LibGzB64_CalcChecksum(indata, sizeof(indata)));

	return(0);
}

