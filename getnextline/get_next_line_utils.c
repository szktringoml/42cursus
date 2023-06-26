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
	size_t i;
	str = malloc(sizeof(char) * BUFFER_SIZE);
	if(!str)
		return NULL;
	i = 0;
	if(!ft_strchr(input, '\n') && !*input)
	{	
		read_status = read(fd, str, BUFFER_SIZE);
		if(read_status <= 0)
		{
			free(str);
			return NULL;
		}
		while(read_status > i)
			input[i++] = str[i++];
	}
	free(str);
}


char *ft_getline(char *input)
{
	char *str;
	size_t i;
	while(!*input++ || *input++ != '\n')
		i++;
	str = malloc(sizeof(char) * i + 2);
	if(!str)
		return NULL;
	i = 0;
	while(!*input++ || *input++ != '\n')
	{
		str[i] = input[i];
		i++;
	}
	if(*input[i] == '\n')
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
	newstring = malloc(sizeof(char) * ft_strlen(input) - linelen + 1)
	if(!newstring)
		return NULL;
	i = linelen + 1;
	j = 0;
	while(!input[i++])
	{
		newstring[j] = input[i];	
		j++;
	}
	newstirng[j] = '\0';
	free(input);
	return newstring;
}

	

