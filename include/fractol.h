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

typedef struct s_map
{
	int				x;
	int				y;
	int             z;
    char            *color;
}   t_map;

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

void init_arry(t_map map[860][540]);
void passing_map(t_map map[860][540], int fd);
void insert_arry(t_map map[860][540]);
void	ft_strfree(char **split_argv, int idx);

# endif