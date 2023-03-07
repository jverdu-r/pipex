/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:14:14 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/02/23 18:56:04 by jverdu-r         ###   ########.fr       */
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
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

void	here_doc(char *limit)
{
	pid_t	read;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		error();
	read = fork();
	if (read == 0)
	{
		close(fd[0]);
		ft_putstr_fd("", fd[1]);
		while (gnllite(&line))
		{
			if (ft_strncmp(line, limit, ft_strlen(limit)) == 0)
				exit(EXIT_SUCCESS);
			ft_putstr_fd(line, fd[1]);
		}
	}
	else
	{
		close(fd[0]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	executor(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(((const char *)argv), ' ');
	path = pathfinder(cmd[0], envp);
	if (!path)
	{
		while (cmd[i++])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
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
			here_doc(argv[2]);
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
