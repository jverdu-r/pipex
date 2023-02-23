/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:14:30 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/02/23 17:02:28 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	usage(void)
{
	ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 1);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("./pipex \"here_doc\" <LIMIT> <cmd1> <cmd2> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

int	open_file(char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		fd = open(argv, O_RDONLY, 0777);
	if (fd == -1)
		error();
	return (fd);
}

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

char	*pathfinder(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = 0;
	while (paths[i++])
		free(paths[i]);
	free(paths);
	return (0);
}

int	gnllite(char **line)
{
	char	*buff;
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buff = (char *)malloc(4096);
	if (!buff)
		return (-1);
	j = read(0, &c, 1);
	while (j && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buff[i] = c;
		i++;
		j = read(0, &c, 1);
	}
	buff[i] = '\n';
	buff[++i] = '\0';
	*line = buff;
	free(buff);
	return (j);
}
