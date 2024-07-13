#include "../include/fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void init_mlx(t_mlx *mlx, t_data *data, t_map *map, t_value ***value)
{
    int count = -1;
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "Hello wrold");
    data->img = mlx_new_image(mlx->mlx, 1920, 1080);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    while (++count < map->high)
    {
        for (int i = 0; i < map->width; i++)
        {
            // printf("%d %d %d %d\n", i, count, value[count][i]->x, value[count][i]->y);
            printf("%d\n", hex_base(value[count][i]->color));
            my_mlx_pixel_put(data, (value[count][i]->x + 300), (value[count][i]->y + 100), hex_base(value[count][i]->color));
        }
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, data->img, 0, 0);
    mlx_loop(mlx->mlx);
}