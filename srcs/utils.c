/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:34:58 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/02/16 18:35:31 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*char   **simple_exec(char *argv)
{   
    char    *cmd[2];

    cmd[0] = argv;
    cmd[1] = "\0";
    return (cmd);
}*/

char    *pathfinder(char *cmd, char **envp)
{
    char    **paths;
    char    *path;
    int     i;

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
            return(path);
        free(path);
        i++;
    }
    i = 0;
    while (paths[i++])
        free(paths[i]);
    free(paths);
    return (0);
}

void    error()
{
    perror("\033[31mError");
    exit(EXIT_FAILURE);
}

void    executor(char *argv, char **envp)
{
    char    **cmd;
    char    *path;
    int     i;

    i = 0;
    /*if (ft_strnstr(argv, " ",ft_strlen(argv))!= 0)
        cmd = simple_exec(argv);
    else*/
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