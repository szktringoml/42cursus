/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 07:57:22 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/25 13:34:58 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
char *get_next_line(int fd)
{
	char *line;
	static char *inputs[1024];
	printf("0\n");
	if(fd < 0 || BUFFER_SIZE < 0)
		return NULL;
	printf("1\n");
	printf("%i",fd);
	ft_input_each_fd(fd, inputs[fd]);
	printf("2\n");
	if(!inputs[fd])
		return NULL;
	line = ft_getline(inputs[fd]);
	printf("3\n");
	inputs[fd] = ft_reshape(inputs[fd], ft_strlen(line));	
	printf("4\n");
	return (line);
}
