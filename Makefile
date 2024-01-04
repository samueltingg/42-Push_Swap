CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -fsanitize=address -g

SRCDIR = srcs/
SRCS_FIL = \
			main.c \
			utils.c \
			checkers.c \
			i_swap.c \
			i_push.c \
			i_rotate.c \
			i_reverse_rotate.c \
			sort_under_six.c \
			assign_index.c \
			list_functions.c \
			split_chunk.c \
			move.c \

SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

OBJDIR = objs/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))


LIBFTDIR = libft/
LIBFT.A = $(LIBFTDIR)libft.a


NAME = push_swap

all:  $(OBJDIR) $(NAME)

$(OBJDIR):
		mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
		make bonus -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

RM = rm -f

clean:
		# $(RM) $(OBJS)
		rm -rf $(OBJDIR)
		make clean -C ${LIBFTDIR}

fclean: clean
		$(RM) $(NAME)
		make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re bonus
