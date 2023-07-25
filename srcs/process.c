/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:09:06 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/25 13:07:09 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid_init(char **envp, t_pipex *pipex)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == 0)
	{
		pid1 = fork();
		if (pid1 == 0)
			child_process(fd, envp, pipex);
		else
			error_check(1);
		pid2 = fork();
		if (pid2 == 0)
			parent_process(fd, envp, pipex);
		else
			error_check(1);
		close(fd[0]);
		close(fd[1]);

	}
	else
		error_check(1);
}

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

// void	make_cmd(char **envp, t_pipex *pipex)
// {

// }
