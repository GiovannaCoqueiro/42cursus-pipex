# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 08:58:42 by gcoqueir          #+#    #+#              #
#    Updated: 2023/08/07 06:59:40 by gcoqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC)
INC = ./include
LIBFT = ./libft
RM = rm -f
FILES = srcs/pipex.c srcs/process.c
OBJS = $(FILES:.c=.o)
BONUS_FILES = srcs/pipex.c
BONUS_OBJS = $(BONUS_FILES:.c=.o)
GREEN = \033[1;32m

all: $(NAME)
	@echo "$(GREEN)SUCCESS!!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME)

bonus: $(BONUS_NAME)
	@echo "$(GREEN)SUCCESS!!"

$(BONUS_NAME): $(BONUS_OBJS)
	@make -C $(LIBFT)
	@$(CC) $(BONUS_OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(BONUS_NAME)

clean:
	@make clean -C $(LIBFT)
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus