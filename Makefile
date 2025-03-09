NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

# LIBFT = libft/libft.a

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
		algo_func_4.c \
		algo_func_5.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

