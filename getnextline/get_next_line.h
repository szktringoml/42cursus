/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 07:58:25 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/30 13:53:44 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <string.h>

#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 20
#endif

size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char *input, char *str);
char *get_next_line(int fd);
char *ft_input_each_fd(int fd, char *input);
char *ft_getline(char *input);
char *ft_reshape(char *input);

#endif
