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
#include <math.h>

typedef struct s_value
{
	double				x;
	double				y;
	int             z;
    int            color;
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

typedef struct s_draw
{
    int xa;
    int xb;
    int ya;
    int yb;
    int add_x;
    int add_y;
    int dx;
    int dy;
    int diff;
    int delta;
    int i;
    int j;
}   t_draw;

//map parsing.c
void init_map(t_map *map, char *str);
void linenb(char *str, int *high , int *widh);
void init_value(t_value *value);
t_value ***alc_map(int high, int width);
void map_parsing(t_value ***value, char *str, t_map *map);
int is_outx(int x);
int is_outy(int y);
void is_max(t_value ***value, t_map *map);
//utils.c
void free_two_arry(char **str, char *lstr, int flag);
void ft_error(char *str);
void free_value(t_value ***value, t_map *map);
int hex_base(char *nptr);
int is_comma(char *nptr);
//utils2.c
int ft_abs(int x);
//is_check.c
void is_vaild(char *str, int fd);
//mt_mlx.c
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void init_mlx(t_mlx *mlx, t_data *data, t_map *map, t_value ***value);
void init_draw(t_draw *draw);
// bresenham.c
void    ft_bresenham(t_draw *draw, int color, t_data *img);

# endif