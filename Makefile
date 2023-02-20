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
GNL			=	inc/get_next_line
PRINTF		=	inc/printf
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
PRINTF_A	=	$(addprefix $(printf), pintf.a)

CC			=	gcc
INCLUDE		=	includes
CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDE)
RM			=	rm -f
SRCS		=	srcs/pipex.c \
				srcs/utils.c

BNSSRCS		=   srcs/pipex_bonus.c \
				srcs/utils_bonus.c

OBJS		=	$(SRCS:%.c=%.o)

BNSOBJS		=	$(BNSSRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(PRINTF_A)
				@$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF) -lft -L$(LIBFT) -lft -o$(NAME)

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)
				@echo "Compiled $(LIBFT_A)."

$(PRINTF_A):
				@$(MAKE) -s -C $(PRINTF)
				@echo "Compiled $(PRINTF_A)."

bonus:
				@$(RM) $(OBJS)
				make OBJS="$(BNSOBJS)"

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@echo "Compiling $<."

localclean:
				@$(RM) $(OBJS) $(BNSOBJS)
				@echo "Removed object files."

fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT)
				@echo "Full clean libft."
				@$(MAKE) fclean -s -C $(PRINTF)
				@echo "Full clean printf."
				@$(RM) $(NAME)
				@echo "Removed executable."

re:				fclean all

.PHONY:			all clean fclean re localclean bonus


