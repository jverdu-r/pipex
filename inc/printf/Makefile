# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:52:10 by jverdu-r          #+#    #+#              #
#    Updated: 2022/03/31 16:58:39 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_pf_putchar.c ft_pf_putdec.c ft_pf_puthexa.c ft_pf_putptr.c \
		  ft_pf_putstr.c ft_printf.c 

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	clean re all fclean
