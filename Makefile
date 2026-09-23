NAME		:= push_swap
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

SRCS		:= main.c ft_atoi.c ft_split.c ft_strdup.c ft_strlen.c normalise_args.c \
			parse_and_fill.c parse_flags.c stack_init.c run_strategy.c sa.c \
			sb.c ss.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c \
			is_sorted.c compute_disorder.c sort_medium.c sort_simple.c \
			sort_adaptive.c sort_complex.c sort_small.c get_pivot.c
			

OBJS		:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
