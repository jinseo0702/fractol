#include "../include/fractol.h"

int ft_abs(int x)
{
    if (x < 0)
        return (x * -1);
    else
        return (x);
}

// int is_good(t_value ***value, t_map *map)
// {
// 	int idx1;
// 	int idx2;

// 	idx1 = 0;
// 	while (idx1 < map->high)
// 	{
// 	idx2 = 0;
// 		while (idx2 < map->width)
// 		{
// 			if (x < 0)
// 				value[idx1][idx2]->x += ft_abs(x);
// 			if (y < 0)
// 				value[idx1][idx2]->y += ft_abs(y);			
// 			if (860 / x_m)
// 				value[idx1][idx2]->x *= (860 / x_m);
// 			if (540 / y_m)
// 				value[idx1][idx2]->y *= (540 / y_m);
// 			idx2++;
// 		}
// 		idx1++;
// 	}
// }