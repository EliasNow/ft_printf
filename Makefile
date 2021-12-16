# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: anijssen <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/04 01:18:55 by anijssen      #+#    #+#                  #
#    Updated: 2020/02/14 17:45:22 by anijssen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c \
		int_padding.c \
		int_print.c \
		padding.c \
		print_conversions.c \
		print_conversions_1.c \
		print_input.c \
		print_utils.c \
		struct_init.c \
		width_precision.c

OBJ = $(SRC:.c=.o)
IDIR = ft_printf.h
CFLAGS = -I $(IDIR) -Werror -Wextra -Wall -g

all:		$(NAME)

$(NAME): $(OBJ)
			@echo "\x1b[1m\x1b[4m\x1b[7m\x1b[38;5;148mCompiling...\x1b[0m"
			@make -C ./libft
			@cp ./libft/libft.a ./$(NAME)
			@ar rcs $(NAME) $(OBJ)

bonus: $(OBJ)
			@echo "\x1b[1m\x1b[4m\x1b[7m\x1b[38;5;148mCompiling...\x1b[0m"
			@make -C ./libft
			@cp ./libft/libft.a ./$(NAME)
			@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $? -o $@ -g

.PHONY:		clean all
clean:
			@echo "\x1b[38;5;196mCleaning...\x1b[0m"
			@rm -f $(OBJ)
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@rm -f $(NAME)

re:		fclean all
