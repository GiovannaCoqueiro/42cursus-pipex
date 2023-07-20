/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:09:06 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/20 08:21:54 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, char **envp, t_pipex *pipex)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	close(fd[0]);
	make_cmd(envp, pipex);
}

void	parent_process(int *fd, char **envp, t_pipex *pipex)
{
	dup2(fd[0], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	close(fd[1]);
	make_cmd(envp, pipex);
}

void	make_cmd(char **envp, t_pipex *pipex)
{

}
