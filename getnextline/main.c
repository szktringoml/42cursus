#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
int main(){
	int fd;
	fd = open("41_no_nl", O_RDWR);
	printf("%i\n",fd);
	get_next_line(fd);
}
