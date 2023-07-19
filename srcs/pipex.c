/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:07:31 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/19 09:43:42 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	program_call_check(argc, argv, &pipex);
	pid_init(argv, envp);
	return (0);
}

void	program_call_check(int argc, char **argv, t_pipex *pipex)
{
	int	count;
	int	index;

	if (argc != 5)
	{
		printf("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n");
		exit(1);
	}
	if (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0)
		error_check(2);
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	count = 1;
	index = -1;
	pipex->cmd = malloc(sizeof(char *) * (argc - 2));
	if (pipex->cmd == NULL)
		error_check(3);
	while (++count < argc - 1)
		pipex->cmd[index++] = argv[count];
	pipex->cmd[index] = NULL;
}

void	pid_init(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == 0)
	{
		pid = fork();
		if (pid == 0)
			child_process(fd, argv, envp);
		else
			error_check(4);




		parent_process(fd, argv, envp);
	}
	else
		error_check(5);
}

void	child_process(int fd, char **argv, char **envp)
{

}

void	parent_process(int fd, char **argv, char **envp)
{

}

void	error_check(int i)
{
	perror("Error");
	exit(i);
}
