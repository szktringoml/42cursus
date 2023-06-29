/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 07:57:22 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/29 13:57:20 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
char *get_next_line(int fd)
{
	char *line;
	static char *inputs[1024];
	if(fd < 0 || BUFFER_SIZE < 0)
		return NULL;
	inputs[fd] = ft_input_each_fd(fd, inputs[fd]);
	if(!inputs[fd])
		return NULL;
	line = ft_getline(inputs[fd]);
	inputs[fd] = ft_reshape(inputs[fd], ft_strlen(line));	
	return (line);
}
