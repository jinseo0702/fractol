# ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/gnl_check_bonus/get_next_line.h"
# include "../libft/gnl_check_bonus/get_next_line_bonus.h"
# include "../ft_printf/libftprintf.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_value
{
	int				x;
	int				y;
	int             z;
    char            *color;
}   t_value;

typedef struct s_map
{
	int high;
	int width;
}	t_map;


typedef struct  s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

typedef struct  s_mlx
{
    void *mlx;
    void *win;
}   t_mlx;

//map parsing.c
void linenb(char *str, int *high , int *widh);
void init_map(t_map *map);
void init_value(t_value *value);
t_value **alc_map(int high, int width);
//utils.c
void free_two_arry(char **str, char *lstr, int flag);
void ft_error(char *str);
//is_check.c
void is_vaild(char *str, int fd);

# endif