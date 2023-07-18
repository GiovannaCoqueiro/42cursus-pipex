/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:18:34 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/05/05 09:18:35 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(214748364, fd);
		write(fd, "8", 1);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		a = (n % 10 + '0');
		write(fd, &a, 1);
	}
	else if (n >= 0 && n <= 9)
	{
		a = (n + '0');
		write(fd, &a, 1);
	}
	else
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
}
