/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 07:29:37 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/08 07:30:09 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

void	error_check(int i, t_pipex *pipex)
{
	if (pipex != NULL)
	{
		if (pipex->all_paths != NULL)
			free_tab(pipex->all_paths);
		if (pipex->cmd != NULL)
			free_tab(pipex->cmd);
	}
	if (i == 2)
		ft_putendl_fd("Error: command not found", 2);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}
