/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:19:24 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/20 08:42:09 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	take_cmd(int argc, char **argv, t_pipex *pipex)
{
	int	count;
	int	index;

	count = argc - 2;
	pipex->cmd = malloc(sizeof(char *) * count);
	if (pipex->cmd == NULL)
		error_check(3);
	index = -1;
	while (++index < count - 1)
	{
		
		pipex->cmd[index] = argv[index + 2];
	}
	pipex->cmd[index] = NULL;
}
