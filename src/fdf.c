#include "../include/fractol.h"

int main(int argc, char **argv)
{
	t_map map;
	t_value ***value;
	// t_mlx *mlx;
	// t_data *data;

	if (argc == 2)
	{
		init_map(&map, argv[1]);
		value = alc_map(map.high, map.width);
		map_parsing(value, argv[1], &map);
		free_value(value, &map);
		exit(0);
	}
	printf("Error\n");
	return (0);
}