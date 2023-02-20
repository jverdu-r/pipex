/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:09:50 by jverdu-r          #+#    #+#             */
/*   Updated: 2023/02/16 18:17:07 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./printf/printf.h"
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>

int	    main(int argc, char **argv, char **envp);
void    executor(char *argv, char **envp);
void    error();

#endif
