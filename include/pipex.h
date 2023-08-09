/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:02:03 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/09 07:00:58 by gcoqueir         ###   ########.fr       */
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
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**cmd;
	char	**all_paths;
}			t_pipex;

void	pid_init(char **argv, char **envp, t_pipex *pipex);
void	make_cmd(char **envp, char *command, t_pipex *pipex);
void	cmd_search(char **envp, t_pipex *pipex);

void	free_tab(char **tab);
void	error_check(int i, t_pipex *pipex);

/*bonus functions*/
void	pipe_it(char *cmd, char **envp, t_pipex *pipex);
void	here_doc(char *end_msg, t_pipex *pipex);

#endif