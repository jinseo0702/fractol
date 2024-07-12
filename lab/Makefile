CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC = test_split.c
OBJS = $(SRC:.c=.o)
NAME = test

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) libft.a libftprintf.a -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean :
	@$(RM) $(OBJS) $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re