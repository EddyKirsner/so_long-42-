SRCS = ft_printf.c \
        ft_utils.c \
        ft_utils2.c

CC = cc

FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
