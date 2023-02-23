# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 19:09:37 by jverdu-r          #+#    #+#              #
#    Updated: 2023/02/20 17:11:01 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
LIBFT		=	inc/libft
LIBFT_A		=	inc/libft/libft.a
PRINTF_A	=	inc/printf/printf.a

CC			=	gcc
INCLUDE		=	includes
CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDE)
RM			=	rm -f
SRCS		=	srcs/pipex.c \
				srcs/utils.c

BNSSRCS		=   srcs/pipex_bonus.c \
				srcs/utils_bonus.c \


OBJS		=	$(SRCS:%.c=%.o)

BNSOBJS		=	$(BNSSRCS:%.c=%.o)

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@echo "Compiling $<."

$(NAME):		$(OBJS) $(LIBFT_A)
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o$(NAME)

all:			$(NAME)

$(LIBFT_A):
				@$(MAKE) -sC $(LIBFT)
				@echo "Compiled $(LIBFT_A)."


bonus:
				@$(RM) $(OBJS)
				make OBJS="$(BNSOBJS)"


localclean:
				@$(RM) $(OBJS) $(BNSOBJS)
				@echo "Removed object files."

fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT)
				@echo "Full clean libft."
				@$(RM) $(NAME)
				@echo "Removed executable."

re:				fclean all

.PHONY:			all clean fclean re localclean bonus


