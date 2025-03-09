NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

LIBFT = libft/libft.a

SRCS =	string_pars.c \
		stack_utils_1.c \
		stack_utils_2.c \
		push_swap.c \
		populate_a.c \
		operations_1.c \
		operations_2.c \
		operations_3.c \
		operations_4.c \
		error_handling.c \
		algo_func_1.c \
		algo_func_2.c \
		algo_func_3.c \
		algo_func_4.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re

