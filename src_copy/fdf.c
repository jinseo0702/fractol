#include "../include/fractol.h"

int main(int argc, char **argv)
{
	t_map map;
	t_value ***value;
	// t_mlx mlx;
	// t_data data;

	if (argc == 2)
	{
		init_map(&map, argv[1]);
		value = alc_map(map.high, map.width);
		map_parsing(value, argv[1], &map);
		for (int count = 0; count < map.high; count++)
		{
			for (int i = 0; i < map.width; i++)
			{
				printf("%d %d %s\n", value[count][i]->x, value[count][i]->y, value[count][i]->color);
				printf("%d\n", hex_base(value[count][i]->color));
			}
		}
		// init_mlx(&mlx, &data, &map, value);
		free_value(value, &map);
		exit(0);
	}
	printf("Error\n");
	return (0);
}