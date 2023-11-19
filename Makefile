SRCS	= ft_printf_main.c ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

CFLAGS	= -Wall -Werror -Wextra

HEADERS = ft_printf.h

CC		= gcc
RM		= rm -f

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re