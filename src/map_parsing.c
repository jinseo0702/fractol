#include "../include/fractol.h"

void init_map(t_map *map)
{
	map->high = 0;
	map->width = 0;
}

void init_value(t_value *value)
{
	value->x = 0;
	value->y = 0;
	value->z = 0;
	value->color = NULL;
}

void linenb(char *str, int *high , int *width)
{
	int fd;
	char *temp;
	char **two;

	if ((fd = open(str, O_RDONLY)) < 0)
		ft_error("file is not open! retry");
	is_vaild(str, fd);
	while ((temp = get_next_line(fd)))
	{
		if (*high == 0)
		{
			two = ft_split(temp, ' ');
			while (two[*width])
				(*width)++;
			free_two_arry(two, NULL, 2);
		}
		free_two_arry(NULL, temp, 1);
		(*high)++;
	}
	close(fd);
}

t_value ***alc_map(int high, int width)
{
	int idx;
	int idx2;
	t_value ***value;

	idx = -1;
	value = (t_value ***)malloc(sizeof(t_value **) * high);
	if (!value)
		ft_error("not allocated malloc");
	while (++idx < high)
	{
		value[idx] = (t_value **)malloc(sizeof(t_value *) * width);
		if (!&value[idx])
			ft_error("not allocated malloc");//이부분은 누수관리가 필요함.
		idx2 = -1;
		while(++idx2 < width)
		{
			init_value(value[idx][idx2]);
		}
	}
	return (value);
}