NAME = libft.a

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RM = rm -f

SOURCES = ft_atoi.c\
ft_bzero.c\
ft_count_chars.c\
ft_count_chars_c.c\
ft_count_words.c\
ft_count_words_c.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_lstadd.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstnew.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_split_whitespaces.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_tolower.c\
ft_toupper.c\

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
		@(echo "\033[32m Librairie :[ \033[31m\t\c")
		@(echo "$@ \033[32m]\033[0m \033[0K")
		@($(CC) $(CFLAGS) -c -o $@ $<)
		@(echo "\033[2F")

$(NAME): $(OBJECT)
		@(ar rc $(NAME) $(OBJECT))
		@(ranlib $(NAME))
		@(echo "\033[2K\033[2F")
		@(echo "\n\033[32m Librairie compilée\033[0m";)


clean:
		@($(RM) $(OBJECT))
		@echo "\033[1;34mLibft\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
		@($(RM) $(NAME))
		@echo "\033[1;34mLibft\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"
		
re: fclean all

.PHONY: clean fclean re