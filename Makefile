# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/17 15:05:19 by mschneid     #+#   ##    ##    #+#        #
#    Updated: 2018/01/29 16:00:08 by mschneid    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCDIR =	srcs

SOURCES =	libft/ft_bzero.c\
			libft/ft_isdigit.c\
			libft/ft_memset.c\
			libft/ft_putchar.c\
			libft/ft_putnbr.c\
			libft/ft_putstr.c\
			libft/ft_strlen.c\
			libft/ft_strsub.c\
			libft/ft_strcat.c\
			libft/ft_strdup.c\
			libft/ft_strdel.c\
			libft/ft_strnew.c\
			libft/ft_strjoin.c\
			libft/ft_strcpy.c\
			libft/ft_toupper.c\
			srcs/ft_printf.c\
			srcs/debug.c\
			srcs/ft_printf_parsing.c\
			srcs/ft_printf_struct.c\
			srcs/ft_printf_process.c\
			srcs/ft_printf_print.c\
			srcs/ft_printf_output.c\
			srcs/ft_itoa_base.c\
			srcs/ft_putwchar.c\

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c includes/ft_printf.h
		@(echo "\033[32m Librairie :[ \033[31m\t\c")
		@(echo "$@ \033[32m]\033[0m \033[0K")
		@($(CC) $(CFLAGS) -I includes -c -o $@ $<)
		@(echo "\033[2F")

$(NAME): $(OBJECT)
		@(ar rc $(NAME) $(OBJECT))
		@(ranlib $(NAME))
		@(echo "\033[2K\033[2F")
		@(echo "\n\033[32m Librairie compilée\033[0m";)


clean:
		@rm -f $(OBJECT)
		@echo "\033[1;34mLibft\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[1;34mLibft\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"
		
re: fclean all

.PHONY: clean fclean re
