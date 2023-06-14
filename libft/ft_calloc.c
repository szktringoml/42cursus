/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 06:10:15 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/06/06 09:44:35 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	t;

	if (size == 0 || nmemb == 0)
		return (ft_calloc(1, 1));
	t = nmemb * size;
	if (t / nmemb != size)
		return (NULL);
	s = malloc(sizeof(void) * t);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
