CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC = src/test.c
MLX = ./minilibx-linux

OBJS = $(SRC:.c=.o)
NAME = fractol

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L$(MLX) -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX) -Imlx_linux -O3 -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : 
	$(RM) $(OBJS) $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re
