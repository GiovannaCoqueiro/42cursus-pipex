/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:07:31 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/20 08:25:34 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	program_call_check(argc, argv);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile == -1)
		error_check(2);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (pipex.outfile == -1)
	{
		close(pipex.infile);
		error_check(2);
	}
	take_cmd(argc, argv, &pipex);
	pid_init(envp, &pipex);
	return (0);
}
