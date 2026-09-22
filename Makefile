NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

FTPRINTF_DIR	= ft_printf
FTPRINTF		= $(FTPRINTF_DIR)/libftprintf.a

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
			  utils_input_validation.c \
			  utils_llst.c \
			  utils_number_validation.c \
			  utils_parse_strategy.c \
			  utils_print_benchmark.c \
			  $(GNL_DIR)/get_next_line.c \
			  $(GNL_DIR)/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(FTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FTPRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
