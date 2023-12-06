CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

SRCDIR = srcs/
INCDIR = ../
LIBFTDIR = libft/

SRCS_FIL = \
			main.c push_swap_utils.c
SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

OBJS = $(SRCS:.c=.o)

LIBFT.A = $(LIBFTDIR)libft.a

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
		make bonus -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

RM = rm -f

clean:
		$(RM) $(OBJS) $(BOBJS) 
		make clean -C ${LIBFTDIR}

fclean: clean
		$(RM) $(NAME) $(LIBFT.A)

re: fclean all

.PHONY: all clean fclean re bonus
