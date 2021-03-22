# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 12:02:21 by afulmini          #+#    #+#              #
#    Updated: 2021/03/19 14:54:16 by afulmini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

HEADER = -I. -I./$(LIBFT_DIR)

SRCS = ./srcs/ft_printf.c ./srcs/ft_print_c.c ./srcs/ft_print_di.c \
		./srcs/ft_print_p.c ./srcs/ft_print_s.c ./srcs/ft_print_u.c ./srcs/ft_print_percent.c \
		./srcs/ft_print_bigx.c ./srcs/ft_print_smallx.c ./srcs/ft_parameters.c \

OBJS = $(SRCS:.c=.o)

CC	= gcc

CFLAGS = -Wall -Werror -Wextra

RM 	= rm -rf

AR = ar rcs

all: $(NAME)

$(NAME):	$(OBJS)
	@echo "Making your printf library ... \033[32mok\033[0m\n"
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "\n\033[32m || DONE | \033[0m\n"

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "Cleaning your .o objetcs ... \033[32mok\033[0m\n"

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "Removing your library ... \033[32mok\033[0m\n"

re:	fclean all

.PHONY: all clean fclean re
