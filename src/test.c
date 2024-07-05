#include "../include/fractol.h"

typedef struct  s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data))
}

int main(void)
{
    void *mlx;
    void *mlx_win;
    t_data *img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello wrold");
    img = mlx_new_image(mlx, 1920, 1080);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

    mlx_loop(mlx);
}