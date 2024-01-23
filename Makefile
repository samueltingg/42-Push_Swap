CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 
# -fsanitize=address -g
INCS = -I ./includes/


SRCDIR = srcs/
SRCS_FIL = \
			main.c \
			create_stack.c \
			check_input_error.c \
			i_swap.c \
			i_push.c \
			i_rotate.c \
			i_reverse_rotate.c \
			list_functions.c \
			sort_under_six.c \
			assign_index.c \
			three_way_quick_sort.c \
			split_chunk_utils.c \
			move.c 

SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

OBJDIR = objs/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

# bonus
BONUS_SRCS_FIL = \
				check_input_error.c \
				create_stack.c \
				i_swap.c \
				i_push.c \
				i_rotate.c \
				i_reverse_rotate.c \
				list_functions.c \
				checker_main_bonus.c \
				do_swap_push_bonus.c \
				do_rotate_bonus.c \
				do_reverse_rotate_bonus.c 
# ^ last line for source files can't end with '\'
BONUS_SRCS = $(addprefix $(SRCDIR), $(BONUS_SRCS_FIL))
BONUS_OBJS = $(addprefix $(OBJDIR), $(notdir $(BONUS_SRCS:.c=.o)))


# library
LIBFTDIR = libft/
LIBFT.A = $(LIBFTDIR)libft.a


NAME = $(PUSH_SWAP) $(CHECKER)
PUSH_SWAP = push_swap
CHECKER = checker

all:  $(OBJDIR) $(PUSH_SWAP)

bonus: $(OBJDIR) $(CHECKER) 

$(OBJDIR):
		mkdir -p $(OBJDIR)

$(PUSH_SWAP): $(OBJS)
		make -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(PUSH_SWAP) -L$(LIBFTDIR) -lft

$(CHECKER): $(BONUS_OBJS)
		make -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(CHECKER) -L$(LIBFTDIR) -lft


$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS) 

RM = rm -f

clean:
		# $(RM) $(OBJS)
		rm -rf $(OBJDIR)
		make clean -C ${LIBFTDIR}

fclean: clean
		$(RM) $(PUSH_SWAP) $(CHECKER)
		make fclean -C $(LIBFTDIR)

re: fclean all

norm: norminette -R CheckDefine | grep "Error"

.PHONY: all clean fclean re bonus
