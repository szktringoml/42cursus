/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 07:58:07 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/29 13:57:21 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if(!s)
		return(NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (s1 ? ft_strlen(s1) : 0) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	if(s1)
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char *ft_input_each_fd(int fd, char *input)
{
	char *str;
	int read_status;
	size_t i;
	str = malloc(sizeof(char) * BUFFER_SIZE);

	if(!str)
		return NULL;
	i = 0;
	if(!ft_strchr(input, '\n') || !input)
	{	
		read_status = read(fd, str, BUFFER_SIZE);
		if(read_status == -1)
		{
			free(str);
			return NULL;
		}
		str[read_status] = '\0';
		if(read_status > (int)i)
			input = ft_strjoin(input,str);
	}
	free(str);

	return input;
}

char *ft_getline(char *input)
{
	char *str;
	size_t i;
	i = 0;
	while(input[i] && input[i] != '\n')
		i++;
	str = malloc(sizeof(char) * i + 2);
	if(!str)
		return NULL;
	i = 0;
	while(input[i] &&  input[i] != '\n')
	{
		str[i] = input[i];
		i++;
		
	}
	if(input[i] == '\n')
	{
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	return str;
}

char *ft_reshape(char *input, size_t linelen)
{
	char *newstring;
	size_t i;
	size_t j;
	newstring = malloc(sizeof(char) * ft_strlen(input) - linelen + 1);
	if(!newstring)
		return NULL;
	i = linelen + 1;
	j = 0;
	while(!input[i++])
	{
		newstring[j] = input[i];	
		j++;
	}
	newstring[j] = '\0';
	free(input);
	return newstring;
}

	

