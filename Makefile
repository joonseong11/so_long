# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 00:30:34 by jujeon            #+#    #+#              #
#    Updated: 2022/07/18 14:51:18 by jujeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = mandatory.c \
		basic_func/ft_calloc.c \
		basic_func/ft_strdup.c \
		basic_func/ft_strjoin.c \
		basic_func/ft_strlen.c \
		basic_func/get_next_line.c \
		basic_func/get_next_line_utils.c \
		init_map.c \
		info_init.c \
		adapt_image.c \
		get_error.c \
		event_key.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
.PHONY : all clean fclean re