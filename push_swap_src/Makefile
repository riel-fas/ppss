NAME = push_swap

BONUS = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

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
		algo_func_5.c \

BONUS_SRC = ../checker/checker.c \
			../checker/error_handling_bonus.c \
			../checker/operations_1_bonus.c \
			../checker/operations_2_bonus.c \
			../checker/operations_3_bonus.c \
			../checker/operations_4_bonus.c \
			../checker/populate_a_bonus.c \
			../checker/stack_utils_1_bonus.c \
			../checker/string_pars_bonus.c \
			../checker/moves_check.c \
			../libft/get_next_line/get_next_line.c

LIBFT = ../libft/libft.a

OBJS = $(SRCS:.c=.o)

BONUS_OBJ = ${BONUS_SRC:.c=.o}

HEADER = push_swap.h

HEADER_BONUS = ../checker/checker.h


all: ${NAME}

bonus: ${BONUS}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS)

$(LIBFT):
	make -C ../libft

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJ)
	make clean -C ../libft

fclean: clean
	rm -rf $(NAME) $(BONUS)
	make fclean -C ../libft

re: fclean all

.PHONY: all clean fclean re bonus
