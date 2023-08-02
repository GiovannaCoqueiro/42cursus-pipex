/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:07:31 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/02 15:24:29 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (program_call_check(argc, argv) == 1)
	{
		pipex.infile = open(argv[1], O_RDONLY);
		if (pipex.infile == -1)
			error_check(NULL);
		pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT
				| O_WRONLY, 0777);
		if (pipex.outfile == -1)
		{
			close(pipex.infile);
			error_check(NULL);
		}
		take_paths(envp, &pipex);
		pid_init(argv, envp, &pipex);
		free_tab(pipex.all_paths);
	}
	return (0);
}

int	program_call_check(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n");
		return (0);
	}
	if (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0)
		error_check(NULL);
	return (1);
}

void	take_paths(char **envp, t_pipex *pipex)
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

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

void	error_check(t_pipex *pipex)
{
	if (pipex != NULL)
	{
		if (pipex->all_paths != NULL)
			free_tab(pipex->all_paths);
		if (pipex->cmd != NULL)
			free_tab(pipex->cmd);
	}
	perror("Error");
	exit(1);
}
