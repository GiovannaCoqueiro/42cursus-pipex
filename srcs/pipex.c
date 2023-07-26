/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:07:31 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/26 09:33:16 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	program_call_check(argc, argv);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile == -1)
		error_check(1);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (pipex.outfile == -1)
	{
		close(pipex.infile);
		error_check(1);
	}
	take_paths(envp, &pipex);
	pid_init(argv, &pipex);
	free_tab(pipex.all_paths);
	return (0);
}

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

void	error_check(int i)
{
	perror("Error");
	exit(i);
}
