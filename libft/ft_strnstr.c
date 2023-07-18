/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:19:09 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/05/05 09:19:10 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	sub_len;
	size_t	lc;
	char	*bbig;

	bbig = (char *)big;
	sub_len = ft_strlen(little);
	if (sub_len == 0)
		return (bbig);
	count = 0;
	while (big[count] != '\0' && count < len)
	{
		lc = 0;
		while (big[count + lc] == little[lc] && count + lc < len)
		{
			if (little[lc + 1] == '\0')
				return (&bbig[count]);
			lc++;
		}
		count++;
	}
	return (NULL);
}
