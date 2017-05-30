# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 09:15:34 by jde-mot           #+#    #+#              #
#    Updated: 2017/02/17 17:12:20 by aserguie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
RM = rm -rf

# PATH
OBJPATH = obj
SRCPATH = .
INCLUDE = -I ./
#

# COMPILATION
CC = gcc
CFLAGS = -Wall -Werror -Wextra
#

# FILES
INCLUDES = $(INCLUDE) $(LFTIPATH)
SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)
SRCSFILES = main_test.c \
			build_lst_tetriminos.c \
			build_tetriminos.c \
			check.c \
			check_3.c \
			checknb.c \
			compact_position.c \
			compact_position_1.c \
			lign_compact_position.c \
			lign_position.c \
			solve.c \
			libft.c \
			libft2.c
#

# COLORS
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
GREY = \033[0;37m
E = \033[39m
#

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) -o $@ $(CFLAGS) -g $(OBJECTS) $(INCLUDES)

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	@$(RM) $(OBJPATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
