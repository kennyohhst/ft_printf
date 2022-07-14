#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
	
int main (void)
{
	char s = 'a';
	long x;
	// char	**adrex

	x = (long) &s;

	// printf("adress s: %ld", x);
	// printf("\nadress s: %ld", &s);
		printf("0x%x   0x%X\n\n\n\n", 'a', 'b');
		printf("%c   %c", 00141, 00143);


	// write(1, &s, 1);
	// write(1, &s, 4);
	return (0);
}