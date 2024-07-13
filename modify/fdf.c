#include "../include/fractol.h"
//this version is uesed printf

int main(int argc, char **argv)
{
	t_map map;
	t_value ***value;

	if (argc == 2)
	{
		init_map(&map);
		linenb(argv[1], &map.high, &map.width);
		value = alc_map(map.high, map.width);
		map_parsing(value, argv[1], &map);
		for(int h = 0; h < map.high; h++)
		{
			for (int w = 0; w < map.width; w++)
			{
				//printf("y == %d, x == %d, z == %d \n", value[h][w]->x, value[h][w]->y, value[h][w]->z);
				printf("%d", value[h][w]->z);
				if (value[h][w]->color != NULL)
					printf(",%s", value[h][w]->color);
				if (value[h][w]->z < 10)
					printf("  ");
				else
					printf(" ");
			}
			printf("\n");
		}
		free_value(value, &map);
		// printf("line count is %d width count is %d, vlaue %d\n", map.high, map.width, value[0][0]->x);
		exit(0);
	}
	printf("Error\n");
	return (0);
}