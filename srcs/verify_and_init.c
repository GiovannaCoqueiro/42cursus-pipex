/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_and_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:07:49 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/25 12:43:26 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	program_call_check(int argc, char **argv)
{
	if (argc != 5)
	{
		printf("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n");
		exit(1);
	}
	if (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0)
		error_check(1);
}

void	pid_init(char **envp, t_pipex *pipex)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == 0)
	{
		pid = fork();
		if (pid == 0)
			child_process(fd, envp, pipex);
		else
			error_check(1);
		pid = fork();
		if (pid == 0)
			parent_process(fd, envp, pipex);
		else
			error_check(1);
	}
	else
		error_check(1);
}

void	error_check(int i)
{
	perror("Error");
	exit(i);
}
