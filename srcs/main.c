/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:22:45 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/02/16 15:58:13 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../inc/pipex.h"*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//Child process routine
void	child_routine(pid_t pid, int *nb)
{
	printf("\nChild: i'm the child. PID received from fork = %d\n", pid);
	printf("\nChild: the number is %d\n", *nb);
}

//Parent process routine
void	parent_routine(pid_t pid, int *nb)
{
	printf("\nParent: i'm the parent. PID received from fork = %d\n", pid);
    printf("\nParent: the number is %d\n", *nb);
	*nb *= 2;
	printf("\nParent: The modified number is %d\n", *nb);
}

int	main(void)
{
	pid_t	pid;
	int		nb;

	nb = 21;
	printf("Before fork, the number is %d\n", nb);
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
		child_routine(pid, &nb);
	else if (pid > 0)
		parent_routine(pid, &nb);
	return (0);
}
