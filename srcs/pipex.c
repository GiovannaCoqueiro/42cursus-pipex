/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:07:31 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/18 09:09:09 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = NULL;
	program_call_check(argc, argv, pipex);
	return (0);
}

void	program_call_check(int argc, char **argv, t_pipex *pipex)
{
	if (argc != 5)
	{
		printf("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n");
		exit(1);
	}
	if (access(argv[1], F_OK) != 0)
	{
		perror("Error");
		exit(2);
	}
	pipex->infile = argv[1];
	pipex->cmd[0] = argv[2];
	pipex->cmd[1] = argv[3];
	pipex->outfile = argv[4];
}
