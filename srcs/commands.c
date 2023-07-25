/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:19:24 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/25 12:40:05 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	take_paths(char **envp, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (envp[i] != NULL && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	pipex->all_paths = ft_split(&envp[i][5], ':');
}
