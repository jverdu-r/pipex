/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:14:14 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/02/22 19:39:46 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_proc(char *arg, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		executor(arg, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limit, int argc)
{
	pid_t	read;
	int		fd[2];
	char	*line;

	if (argc < 6)
		usage();
	if (pipe(fd) == -1)
		error();
	read = fork();
	if (read == 0)
	{
		close(fd[0]);
		line = get_next_line(fd[1]);
		while (get_next_line(fd[1]))
		{
			if (ft_strncmp(line, limit, ft_strlen(limit)) == 0)
				exit(EXIT_SUCCESS);
			ft_putstr_fd(line, fd[1]);
			line = get_next_line(fd[1]);
		}
	}
	else
	{
		close(fd[0]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	file_in;
	int	file_out;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			file_out = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			file_out = open_file(argv[argc - 1], 1);
			file_in = open_file(argv[1], 2);
			dup2(file_in, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_proc(argv[i++], envp);
		dup2(file_out, STDOUT_FILENO);
		executor(argv[argc - 2], envp);
	}
	usage();
}
