/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:07:31 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/19 08:27:16 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = NULL;
	program_call_check(argc, argv, &pipex);
	create_pipe(&pipex);
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
	{
		perror("Error");
		exit(2);
	}
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	count = 1;
	index = -1;
	while (++count < argc - 1)
		pipex->cmd[index++] = argv[count];
}

void	pid_init(t_pipex *pipex)
{
	int	fd[2];
	int	pid[2];

	if (pipe(fd) == -1)
	{
		perror("Error");
		exit(3);
	}
	pid[1] = fork();
}
