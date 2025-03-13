NAME = push_swap

BONUS = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS =	push_swap_src/string_pars.c \
		push_swap_src/stack_utils_1.c \
		push_swap_src/stack_utils_2.c \
		push_swap_src/push_swap.c \
		push_swap_src/populate_a.c \
		push_swap_src/operations_1.c \
		push_swap_src/operations_2.c \
		push_swap_src/operations_3.c \
		push_swap_src/operations_4.c \
		push_swap_src/error_handling.c \
		push_swap_src/algo_func_1.c \
		push_swap_src/algo_func_2.c \
		push_swap_src/algo_func_3.c \
		push_swap_src/algo_func_4.c \
		push_swap_src/algo_func_5.c \

BONUS_SRC = checker_src/checker.c \
			checker_src/error_handling_bonus.c \
			checker_src/operations_1_bonus.c \
			checker_src/operations_2_bonus.c \
			checker_src/operations_3_bonus.c \
			checker_src/operations_4_bonus.c \
			checker_src/populate_a_bonus.c \
			checker_src/stack_utils_1_bonus.c \
			checker_src/string_pars_bonus.c \
			libft/get_next_line/get_next_line.c

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

BONUS_OBJ = ${BONUS_SRC:.c=.o}

HEADER = push_swap.h

HEADER_BONUS = checker_src/checker.h


all: ${NAME}

bonus: ${BONUS}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS)

$(LIBFT):
	make -C libft

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(BONUS)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
