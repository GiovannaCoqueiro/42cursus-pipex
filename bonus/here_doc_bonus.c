/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:27:34 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/09 07:00:51 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	here_doc_utils(int *fd, char *end_msg, t_pipex *pipex);

void	here_doc(char *end_msg, t_pipex *pipex)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_check(4, pipex);
	pid = fork();
	if (pid == -1)
		error_check(4, pipex);
	if (pid == 0)
		here_doc_utils(fd, end_msg, pipex);
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		waitpid(pid, NULL, WNOHANG);
	}
}

static void	here_doc_utils(int *fd, char *end_msg, t_pipex *pipex)
{
	char	*temp;

	close(fd[0]);
	while (1)
	{
		temp = get_next_line(0);
		if (ft_strncmp(temp, end_msg, ft_strlen(end_msg)) == 0)
		{
			free(temp);
			close(pipex->outfile);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(temp, fd[1]);
		free(temp);
	}
}
