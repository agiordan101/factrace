# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/15 15:27:07 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/05/17 14:58:31 by agiordan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = factrace

SRCS_PATH =	srcs
SRCS_FILES =	main.c \
				init_prime_numbers.c \
				algo.c \
				lst.c \
				ft_utils.c \
				ft_atoi.c
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

OBJS_PATH = objs
OBJS_FILES = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_FILES))

LIB = libgmp

INCLUDES_PATH = includes
CC = gcc
CFLAGS += -g -Wall -Wextra -Werror -I./$(INCLUDES_PATH)\
		  							-I./$(LIB)

all:	directory $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIB)/.libs/libgmp.a -o $(NAME)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

directory:
		@mkdir $(OBJS_PATH) 2> /dev/null || true

clean:
		rm -rf $(OBJS_PATH)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all

norme:
		@norminette $(SRCS_PATH)
		@norminette $(INCLUDES_PATH)

.PHONY: all, clean, fclean, re, directory, norme
