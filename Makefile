CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99  
# -fsanitize=address -g

SRCDIR = srcs/
SRCS_FIL = \
			main.c \
			check_input_error.c \
			i_swap.c \
			i_push.c \
			i_rotate.c \
			i_reverse_rotate.c \
			sort_under_six.c \
			assign_index.c \
			list_functions.c \
			three_way_quick_sort.c \
			split_chunk_utils.c \
			move.c \

SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

OBJDIR = objs/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))


LIBFTDIR = libft/
LIBFT.A = $(LIBFTDIR)libft.a


NAME = $(PUSH_SWAP) $(CHECKER)
PUSH_SWAP = push_swap
CHECKER = checker

all:  $(OBJDIR) $(PUSH_SWAP)

$(OBJDIR):
		mkdir -p $(OBJDIR)

$(PUSH_SWAP): $(OBJS)
		make bonus -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(PUSH_SWAP) -L$(LIBFTDIR) -lft

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

RM = rm -f

clean:
		# $(RM) $(OBJS)
		rm -rf $(OBJDIR)
		make clean -C ${LIBFTDIR}

fclean: clean
		$(RM) $(PUSH_SWAP)
		make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re bonus
