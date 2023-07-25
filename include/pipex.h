/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:02:03 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/25 12:38:28 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		cmd_nbr;
	char	**cmd;
	char	**all_paths;
}			t_pipex;

void	program_call_check(int argc, char **argv);
void	take_paths(char **envp, t_pipex *pipex);


void	pid_init(char **envp, t_pipex *pipex);
void	child_process(int *fd, char **envp, t_pipex *pipex);
void	parent_process(int *fd, char **envp, t_pipex *pipex);
// void	make_cmd(char **envp, t_pipex *pipex);

void	error_check(int i);

#endif