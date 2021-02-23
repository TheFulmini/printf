# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 13:19:38 by afulmini          #+#    #+#              #
#    Updated: 2021/02/15 17:34:25 by afulmini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PATH_OPRINTF = ./src/
PATH_SPRINTF = ./src/
PATH_IPRINTF = ./src/
PATH_OLIBFT = ./libft/
PATH_SLIBFT = ./libft/
PATH_ILIBFT = ./libft/
FILESLIBFT = ft_strlen ft_putchar ft_putchar_fd ft_putstr ft_putstr_fd ft_putnchar ft_isdigit ft_strchr ft_isspace \
			ft_atoi ft_putnbr ft_putnbr_fd ft_itoa ft_strdup ft_strnew ft_bzero ft_strcpy ft_memalloc
FILESPRINTF = ft_printf ft_flags ft_conversion ft_commun ft_putc ft_puts ft_putdi ft_putx ft_putu ft_putp

SLIBFT = $(addprefix $(PATH_SLIBFT), $(addsuffix .c, $(FILESLIBFT)))
OLIBFT = $(addprefix $(PATH_OLIBFT), $(addsuffix .o, $(FILESLIBFT:.c=.o)))
ILIBFT = $(addprefix $(PATH_ILIBFT), libft.h)
SPRINTF = $(addprefix $(PATH_SPRINTF), $(addsuffix .c, $(FILESPRINTF)))
OPRINTF = $(addprefix $(PATH_OPRINTF), $(addsuffix .o, $(FILESPRINTF:.c=.o)))
IPRINTF = $(addprefix $(PATH_IPRINTF), ft_printf.h)

all : $(NAME)

$(NAME) : $(OLIBFT) $(OPRINTF)
	@ar rcs $(NAME) $(OPRINTF) $(OLIBFT)
	@echo "\033[0mCreating your function ...  \033[32mok\033[0m"

$(PATH_OLIBFT)%.o : $(PATH_SLIBFT)%.c $(ILIBFT)
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_ILIBFT)

$(PATH_OPRINTF)%.o : $(PATH_SPRINTF)%.c $(IPRINTF)
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_IPRINTF)

clean:	
			@rm -f $(OLIBFT) $(OPRINTF)
			@echo "\n\033[32m"
			@echo " ██████ ██      ███████  █████  ███    ██"
			@echo "██      ██      ██      ██   ██ ████   ██"
			@echo "██      ██      █████   ███████ ██ ██  ██"
			@echo "██      ██      ██      ██   ██ ██  ██ ██"
			@echo " ██████ ███████ ███████ ██   ██ ██   ████"
			@echo "\033[0m\nRemoving files *.o  ... \033[32mok\033[0m"

fclean:		clean
			@rm -f ${NAME}
			@echo "\033[0mRemoving "${NAME}" ... \033[32mok\033[0m"
			
re:		fclean	all
