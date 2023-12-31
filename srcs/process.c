/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:09:06 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/09 07:02:59 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(int *fd, char **argv, char **envp, t_pipex *pipex);
static void	parent_process(int *fd, char **argv, char **envp, t_pipex *pipex);

void	pid_init(char **argv, char **envp, t_pipex *pipex)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error_check(1, pipex);
	pid = fork();
	if (pid == -1)
		error_check(1, pipex);
	if (pid == 0)
		child_process(fd, argv, envp, pipex);
	waitpid(pid, NULL, WNOHANG);
	parent_process(fd, argv, envp, pipex);
}

static void	child_process(int *fd, char **argv, char **envp, t_pipex *pipex)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	close(fd[0]);
	make_cmd(envp, argv[2], pipex);
}

static void	parent_process(int *fd, char **argv, char **envp, t_pipex *pipex)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(fd[1]);
	make_cmd(envp, argv[3], pipex);
}

void	make_cmd(char **envp, char *command, t_pipex *pipex)
{
	int		i;

	pipex->cmd = ft_split(command, ' ');
	i = -1;
	while (pipex->cmd[++i] != NULL)
		pipex->cmd[i] = ft_strtrim(pipex->cmd[i], "'");
	if (ft_strchr(pipex->cmd[0], '/') != NULL)
		if (execve(pipex->cmd[0], pipex->cmd, envp) == -1)
			error_check(1, pipex);
	cmd_search(envp, pipex);
}

void	cmd_search(char **envp, t_pipex *pipex)
{
	int		i;
	char	*temp;

	i = -1;
	while (pipex->all_paths[++i] != NULL)
	{
		temp = ft_strjoin(pipex->all_paths[i], pipex->cmd[0]);
		if (access(temp, F_OK) == 0)
		{
			if (execve(temp, pipex->cmd, envp) == -1)
			{
				free(temp);
				error_check(1, pipex);
			}
		}
		free(temp);
	}
	if (pipex->all_paths[i] == NULL)
		error_check(2, pipex);
}
