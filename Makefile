CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC = src/fdf.c \
src/map_parsing.c \
src/utils.c \
src/is_check.c \

MLX = ./minilibx-linux

OBJS = $(SRC:.c=.o)
NAME = fdf

all : $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@make -C ft_printf/
	@$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L$(MLX) -lXext -lX11 -lm -lz -L libft/ -lft -L ft_printf/ -lftprintf -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -I$(MLX) -Imlx_linux -O3 -c $< -o $@

clean :
	@make clean -C libft/
	@make clean -C ft_printf/
	@$(RM) $(OBJS)

fclean :
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@$(RM) $(OBJS) $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re
