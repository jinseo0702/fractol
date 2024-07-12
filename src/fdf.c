#include "../include/fractol.h"

int main(int argc, char **argv)
{
	t_map map;
	t_value ***value;

	if (argc == 2)
	{
		init_map(&map);
		linenb(argv[1], &map.high, &map.width);
		value = alc_map(map.high, map.width);
		printf("line count is %d width count is %d, vlaue %d\n", map.high, map.width, value[0][0]->x);
		exit(0);
	}
	printf("Error\n");
	return (0);
}