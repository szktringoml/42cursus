#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main(){
	int fd;
	fd = open("files/empty", O_RDWR);
	printf("output = %s\n",get_next_line(fd));
}
