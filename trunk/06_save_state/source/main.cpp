#include <nds.h>
#include <stdio.h>
#include <string.h>

void writeSRAM(char *src, int size)
{
	for (int i = 0; i < size; i++)
		SRAM[i] = (u8)src[i];
}

void readSRAM(char *dest)
{
	for (int i = 0; SRAM[i] != 0xFF; i++)
		dest[i] = (char)SRAM[i];
}

int main(void)
{
	consoleDemoInit();
	char msg[] = "Thiago Auler dos Santos";
	char out[128];
	int len = strlen(msg);
	int i = 0;
	
	while(true)
	{
		consoleClear();
		
		writeSRAM(msg, len + 1);
		readSRAM(out);
		printf("Mensagem: %s %d\n", out, i++);
		
		swiWaitForVBlank();
	}
}
