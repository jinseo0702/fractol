#include "../include/fractol.h"

static void ft_bresenham_op(t_draw *draw, int color, t_data *img)
{
    while (1)
    {
        my_mlx_pixel_put(img, draw->xa, draw->ya, color);
        if (draw->xa == draw->xb && draw->ya == draw->yb)
            break ;
        draw->delta = draw->diff;
        if (draw->delta > -(draw->dx))
        {
            draw->diff -= draw->dy;
            draw->xa += draw->add_x;
        }
        if (draw->delta < draw->dy)
        {
            draw->diff += draw->dx;
            draw->ya += draw->add_y;
        }
    }
}
void    ft_bresenham(t_draw *draw, int color, t_data *img)
{
    draw->dx = abs(draw->xb - draw->xa);
    draw->dy = abs(draw->yb - draw->ya);
    if (draw->xa < draw->xb)
        draw->add_x = 1;
    else
        draw->add_x = -1;
    if (draw->ya < draw->yb)
        draw->add_y = 1;
    else
        draw->add_y = -1;
    if (draw->dx > draw->dy)
        draw->diff = draw->dx / 2;
    else
        draw->diff = -(draw->dy) / 2;
    ft_bresenham_op(draw, color, img);
}