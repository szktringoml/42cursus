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


char *get_next_line(int fd)
{
	char *line;
	static char *inputs[1024];
	if(fd < 0 || fd == NULL || BUFFER_SIZE < 0)
		return NULL;
	ft_input_each_fd(fd, inputs[fd]);
	if(!inputs[fd])
		return NULL;
	line = ft_getline(input[fd]);
	inputs = ft_reshape(input[fd], ft_strlen(line));	
	return (line);
}
