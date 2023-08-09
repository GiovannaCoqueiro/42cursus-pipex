/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:07:31 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/08 13:22:39 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	take_paths(char **envp, t_pipex *pipex);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		pipex.infile = open(argv[1], O_RDONLY);
		if (pipex.infile != -1)
		{
			pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT
					| O_WRONLY, 0777);
			if (pipex.outfile == -1)
			{
				close(pipex.infile);
				error_check(1, NULL);
			}
			take_paths(envp, &pipex);
			pid_init(argv, envp, &pipex);
			free_tab(pipex.all_paths);
		}
		else
			ft_putendl_fd("Error: No such file or directory", 2);
	}
	else
		ft_putendl_fd("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>", 2);
	return (0);
}

static void	take_paths(char **envp, t_pipex *pipex)
{
	int		i;
	char	**temp;

	i = 0;
	while (envp[i] != NULL && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	temp = ft_split(&envp[i][5], ':');
	i = 0;
	while (temp[i] != NULL)
		i++;
	pipex->all_paths = malloc(sizeof(char *) * (i + 1));
	if (pipex->all_paths == NULL)
	{
		free_tab(temp);
		exit(1);
	}
	i = -1;
	while (temp[++i] != NULL)
		pipex->all_paths[i] = ft_strjoin(temp[i], "/");
	pipex->all_paths[i] = NULL;
	free_tab(temp);
}
