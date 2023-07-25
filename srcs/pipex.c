/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:07:31 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/25 12:38:16 by gcoqueir         ###   ########.fr       */
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
	// pid_init(envp, &pipex);




	int i = -1;
	while (pipex.all_paths[++i] != NULL)
		free(pipex.all_paths[i]);
	free(pipex.all_paths);
	return (0);
}
