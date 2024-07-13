#include "../include/fractol.h"

void free_two_arry(char **str, char *lstr, int flag)
{
	int idx;

	idx = 0;
	if (flag == 2)
	{
		while (str[idx])
		{
			free(str[idx]);
			str[idx] = NULL;
			idx++;
		}
		free(str);
		str = NULL;
	}
	else
	{
		free(lstr);
		lstr = NULL;
	}
}

void free_value(t_value ***value, t_map *map)
{
	int idx1;
	int idx2;

	idx1 = 0;
	while (idx1 < map->high)
	{
		idx2 = 0;
		while (idx2 < map->width)
		{

			free(value[idx1][idx2]);
			value[idx1][idx2] = NULL;
			idx2++;
		}
		free(value[idx1]);
		value[idx1] = NULL;
		idx1++;
	}
	free(value);
}

void ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int hex_base(char *nptr)
{
	int	nb;
	char *nptr2;

	if ((void *)nptr == NULL)
		return (0xFFFFFF);
	nb = 0;
	nptr2 = ft_strdup(strchr(nptr, 'x') + 1);
	while (*nptr2)
	{
		nb = (*nptr - 48) + (nb * 16);
		nptr++;
	}
	free(nptr2);
	return (nb);
}
