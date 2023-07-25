#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	unsigned char c = 227;
	write(1, &c, 1);
	c = 129;
	write(1, &c, 1);
	c = 130;
	write(1, &c, 1);

	return 0;

}
