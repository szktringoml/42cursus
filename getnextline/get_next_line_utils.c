/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 07:58:07 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/25 13:34:57 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_input_each_fd(int fd, char *input)
{
	char *str;
	int read_status;
	str = malloc(sizeof(char) * BUFFER_SIZE);
	if(!str)
		return NULL;
	read_status = read(fd, str, BUFFER_SIZE);
	if(read_status >= 0)

