# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: anijssen <anijssen@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/28 22:04:55 by anijssen      #+#    #+#                  #
#    Updated: 2020/02/01 06:24:22 by anijssen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a
SRC = 		ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_putnbr_fd.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_setcheck.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_swap.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_ultoa.c \
			ft_ultoa_base.c
OBJ = $(SRC:.c=.o)
CC = 		gcc
IDIR = 		libft.h
CFLAGS = 	-I $(IDIR) -Werror -Wextra -Wall

all: 		$(NAME)

$(NAME): $(OBJ)
			@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $? -o $@

.PHONY: 	clean all
clean:
			@rm -f $(OBJ)

fclean: 	clean
			@rm -f $(NAME)

re: 		fclean all
