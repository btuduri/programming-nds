#include <PA9.h>

int main(int argc, char **argv)
{
	PA_Init();
	PA_InitVBL();

	PA_InitText(0, 2);
	PA_OutputSimpleText(0, 1, 2, "Hello World!");

	while (true)
	{
		PA_WaitForVBL();
	}
	
	return 0;
}
