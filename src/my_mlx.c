#include "../include/fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void init_mlx(t_mlx *mlx, t_data *data, t_map *map, t_value ***value)
{
    t_draw draw;
    int count = -1;
    int j = 0;
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "Hello wrold");
    data->img = mlx_new_image(mlx->mlx, 1920, 1080);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    while (++count < map->high)
    {
        for (int i = 0; i < map->width; i++)
        {
            if (i + 1 < map->width)
            {
                j = i + 1;
                init_draw(&draw);
                draw.xa = value[count][i]->x;
                draw.ya = value[count][i]->y;
                draw.xb = value[count][j]->x;
                draw.yb = value[count][j]->y;
             ft_bresenham(&draw, value[count][i]->color, data);
            }
            if (count + 1 < map->high)
            {
                init_draw(&draw);
                draw.xa = value[count][i]->x;
                draw.ya = value[count][i]->y;
                draw.xb = value[count+1][i]->x;
                draw.yb = value[count+1][i]->y;
                ft_bresenham(&draw, value[count][i]->color, data);
            }
            // my_mlx_pixel_put(data, (value[count][i]->x), (value[count][i]->y), value[count][i]->color);
        }
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, data->img, 0, 0);
    mlx_loop(mlx->mlx);
}

void init_draw(t_draw *draw)
{
    draw->xa = 0;
    draw->xb = 0;
    draw->ya = 0;
    draw->yb = 0;
    draw->add_x = 0;
    draw->add_y = 0;
    draw->dx = 0;
    draw->dy = 0;
    draw->diff = 0;
    draw->delta = 0;
    draw->i = 1;
    draw->j = 1;
}