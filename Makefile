NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

GNL_DIR		= get_next_line

SRCS		= algo_complex.c \
			  algo_medium.c \
			  algo_simple.c \
			  op_push.c \
			  op_reverse_rotate.c \
			  op_rotate.c \
			  op_swap.c \
			  push_swap.c \
			  utils_disorder.c \
			  utils_error.c \
			  utils_input_validation.c \
			  utils_llst.c \
			  utils_number_validation.c \
			  utils_parse_strategy.c \
			  utils_print_benchmark.c \

OBJS		= $(SRCS:.c=.o)

COMMON_SRCS	= op_push.c \
			  op_reverse_rotate.c \
			  op_rotate.c \
			  op_swap.c \
			  utils_error.c \
			  utils_input_validation.c \
			  utils_llst.c \
			  utils_number_validation.c

COMMON_OBJS	= $(COMMON_SRCS:.c=.o)

BONUS_SRCS	= checker.c \
			  $(GNL_DIR)/get_next_line.c

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(COMMON_OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(COMMON_OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
