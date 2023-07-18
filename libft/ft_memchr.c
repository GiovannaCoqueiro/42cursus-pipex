/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:18:04 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/05/05 09:18:05 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		count;
	const char	*block;

	block = (const char *)s;
	count = 0;
	while (count < n)
	{
		if (block[count] == (char)c)
			return ((void *)&block[count]);
		count++;
	}
	return (NULL);
}
