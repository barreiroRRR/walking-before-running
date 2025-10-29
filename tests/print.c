#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	char *buff = "write(): Hola, mundo!\n";
	write(1, buff, strlen(buff));
	fputs("fputs(): Hola, mundo!\n", stdout);
	puts("puts(): Hola, mundo!\n");
	
	return 0;
}

