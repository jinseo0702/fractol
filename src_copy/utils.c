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
	long int	nb;
	char *nptr2;
	char *hex_base;

	hex_base = "0123456789abcedf";
	if ((void *)nptr == NULL)
		return (0xFFFFFF);
	nb = 0;
	nptr2 = (strchr(nptr, 'x') + 1);
	while (*nptr2)
	{
		nb = (ft_strchr(hex_base, ft_tolower(*nptr2)) - hex_base) + (nb * 16);
		nptr2++;
	}
	return (nb);
}
