/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:09:06 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/26 09:34:11 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid_init(char **argv, t_pipex *pipex)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) != -1)
	{
		pid = fork();
		if (pid == 0)
			child_process(fd, argv, pipex);
		else if (pid == -1)
			error_check(1);
		waitpid(pid, NULL, 0);
		parent_process(fd, argv, pipex);
		close(fd[0]);
		close(fd[1]);
	}
	else
		error_check(1);
}

void	child_process(int *fd, char **argv, t_pipex *pipex)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	close(fd[0]);
	make_cmd(argv[2], pipex);
}

void	parent_process(int *fd, char **argv, t_pipex *pipex)
{
	dup2(fd[0], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	close(fd[1]);
	make_cmd(argv[3], pipex);
}

void	make_cmd(char *command, t_pipex *pipex)
{
	int		i;
	char	*temp;


	pipex->cmd = ft_split(command, ' ');
	i = -1;
	while (pipex->all_paths[++i] != NULL)
	{
		temp = ft_strjoin(pipex->all_paths[i], pipex->cmd[0]);
		printf("%s\n", temp);
	}
	free(temp);
	free_tab(pipex->cmd);
}
