#include<stdio.h>

int main(void)
{
	int c = 0;
	ciclo:
		printf("Hello World\n");
		c++;
	if(c < 10) goto ciclo;

	return 0;
}
