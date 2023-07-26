/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:07:31 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/26 12:48:38 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	take_cmd(char *command, t_pipex *pipex)
// {
// 	int		i;
// 	char	*temp;

// 	pipex->cmd = ft_split(command, ' ');
// 	i = -1;
// 	while (pipex->all_paths[++i] != NULL)
// 	{
// 		temp = ft_strjoin(pipex->all_paths[i], pipex->cmd[0]);
// 		if (access(temp, F_OK) == 0)
// 			break ;
// 		free(temp);
// 	}
// 	printf("%s\n", temp);
// 	free(temp);
// 	free_tab(pipex->cmd);
// }


int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	program_call_check(argc, argv);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile == -1)
		error_check(1);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (pipex.outfile == -1)
	{
		close(pipex.infile);
		error_check(1);
	}
	take_paths(envp, &pipex);
	// take_cmd(argv[2], &pipex);
	// take_cmd(argv[3], &pipex);
	pid_init(argv, envp, &pipex);
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
