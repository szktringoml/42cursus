#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


#ifndef FDF_FILE_PATH
 # define FDF_FILE_PATH "test_maps/10-2.fdf"
#endif
typedef struct s_fdf{
	size_t height;
	size_t width;
	int **z_values;



}			t_fdf;


#endif
