#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
int main(){
	int fd;
	fd = open("files/nl", O_RDWR);
	printf("output = %s\n",get_next_line(fd));
}
