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

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
    void *mlx;
    void *mlx_win;
    t_data img;
    (void)argc; 

    mlx = mlx_init();//mlx를 초기화 시키지 않으면 error 발생
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello wrold");//window를 띄우는 함수
    img.img= mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    int count = 0;
    while (++count < 1920)
    {
        for (size_t i = 0; i < 1080; i++)
        {
            my_mlx_pixel_put(&img, count, i, 0x00ff0000);
        }
        count += atoi(argv[1]);
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

    mlx_loop(mlx);
}

//아이소 매트릭 브레젠험