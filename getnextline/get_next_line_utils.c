/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 07:58:07 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/30 13:53:44 by kousuzuk         ###   ########.fr       */
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
	if ((char)c == '\0')
		return ((char *)(s + i));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(!s)
		return 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *input, char *str)
{
	char	*str_concat;
	size_t	i;
	size_t	j;
	i = 0;
	j = 0;
	////printf("%s\n",str);
	if(!input)
	{
		input = (char *)malloc(sizeof(char) );
		if(!input)
			return NULL;
		input[0] = '\0';
	}
	if(!input || !str)
		return NULL;
	str_concat = malloc(sizeof(char) * (ft_strlen(input) + ft_strlen(str) + 1));
	if (!str_concat)
		return (NULL);
	i = -1;
	j = 0;
	if(input)
		while(input[++i] != '\0')
			str_concat[i] = input[i];
	//while (input[i] != '\0'){
	//	str_concat[i] = input[i];i++;}

	while (str[j] != '\0')
	{
		str_concat[i++] = str[j++];
	}
	////printf("j = %zu\n",j);
	//str_concat[i + j] = '\0';
	str_concat[ft_strlen(input) + ft_strlen(str)] = '\0';
	free(input);
	////printf("%s\n",str_concat);
	
	return (str_concat);
}

char *ft_input_each_fd(int fd, char *input)
{
	char *str;
	int read_status;
	str = malloc(sizeof(char) * (BUFFER_SIZE+1));
	if(!str)
		return NULL;
	read_status = 1;
	while(!ft_strchr(input, '\n') && read_status != 0)
	{	
		read_status = read(fd, str, BUFFER_SIZE);
		if(read_status == -1)
		{
			free(str);
			return NULL;
		}
		str[read_status] = '\0';
		input = ft_strjoin(input, str);
	}
	free(str);
	////printf("%s\n",input);
	return input;
}

char *ft_getline(char *input)
{
	char *str;
	size_t i;
	i = 0;
	if(!input[i])
		return NULL;
	while(input[i] && input[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
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

char *ft_reshape(char *input)
{
	char *newstring;
	size_t i;
	size_t j;
	i = 0;
	while(input[i] && input[i] != '\n')
		i++;
	if(!input[i])
	{
		free(input);
		return NULL;
	}
	newstring = (char *)malloc(sizeof(char) * (ft_strlen(input) - i + 1));
	if(!newstring)
		return NULL;
	i++;
	j = 0;
	while(input[i])
	{
		newstring[j++] = input[i++];	
	}
	newstring[j] = '\0';
	free(input);
	return newstring;
}
