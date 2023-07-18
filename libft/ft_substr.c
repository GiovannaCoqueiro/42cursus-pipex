/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:19:16 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/05/05 09:19:17 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	char	*str;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	slen = ft_strlen(str);
	if (start > slen)
		return (ft_strdup("\0"));
	if (start + len > slen)
		dest = (char *)malloc(slen - start + 1 * sizeof(char));
	else
		dest = (char *)malloc(len + 1 * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, str + start, len + 1);
	return (dest);
}
