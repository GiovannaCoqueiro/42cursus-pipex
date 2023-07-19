/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:02:03 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/19 09:29:44 by gcoqueir         ###   ########.fr       */
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
	char	*infile;
	char	*outfile;
	char	**cmd;
}			t_pipex;

void	program_call_check(int argc, char **argv, t_pipex *pipex);
void	pid_init(char **argv, char **envp);

void	error_check(int i);

#endif