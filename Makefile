SRCS = so_long.c so_long_map.c so_long_error.c so_long_utils.c so_long_utils2.c so_long_print.c
GNL_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c
PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/ft_utils.c ft_printf/ft_utils2.c

CC = cc
FLAGS = 

NAME = so_long.a
EXEC = so_long

MLX_DIR = minilibx
GNL_DIR = gnl
PRINTF_DIR = printf
MLX = $(MLX_DIR)/libmlx.a

INCLUDES = -I$(MLX_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR)

OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o) $(PRINTF_SRCS:.c=.o)

MLX_FLAGS = -lXext -lX11 -lbsd

all : $(NAME) $(EXEC)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(EXEC) : $(OBJS) $(MLX)
	$(CC) $(FLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) -o $(EXEC)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	rm -rf ${MLX_DIR}/obj

fclean: clean
	rm -f $(NAME) $(EXEC)
	rm -f ${MLX}

re : fclean all

.PHONY : all clean fclean re







