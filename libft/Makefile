CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 
NAME = libft.a

SRCS = \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstlast.c
OBJS = $(SRCS:.c=.o)

# bonus
BSRCS = \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
		# ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BOBJS = $(BSRCS:.c=.o)

# ft_printf
PSRCS = $(addprefix ft_printf/, $(PSRCS_FIL))
PSRCS_FIL = \
			ft_printf.c \
			check_flags.c \
			digit_count_base.c \
			write_padding.c \
			ft_putnbr_base.c \
			ft_putnbr_long.c \
			print_char.c \
			print_str.c \
			print_ptr.c \
			print_uint.c \
			print_int.c \
			print_hex.c \
			
POBJS = $(PSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(POBJS)
		ar -rc $(NAME) $(OBJS) $(POBJS)

bonus: $(OBJS) $(BOBJS) $(POBJS)
		ar -rc $(NAME) $(OBJS) $(BOBJS) $(POBJS)

%.o:%.cd
	cc $(CFLAGS) -c $< -o $@

RM = rm -f

clean:
		$(RM) $(OBJS) $(BOBJS) $(POBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean all
