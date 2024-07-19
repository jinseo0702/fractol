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
	int nb;
	char **two;
	int idx;

	nb = 0;
	idx = -1;
	if (is_comma(nptr))
	{
		two = ft_split(nptr, ',');
		while(two[1][++idx])
			two[1][idx] = ft_tolower(two[1][idx]);
		idx = 2;
		while (ft_isalnum(two[1][idx]))
		{
			if (ft_isalnum(two[1][idx]) == 10)
				nb = (two[1][idx] - 48) + (nb * 16);
			else if (ft_isalnum(two[1][idx]) == 8)
				nb = (two[1][idx] - 87) + (nb * 16);
			idx++;
		}
		free_two_arry(two, NULL, 2);
		return (nb);
	}
	else
		return (0xFFFFFF);
}

int is_comma(char *nptr)
{
	int idx;

	idx = 0;
	while (nptr[idx])
	{
		if (nptr[idx] == ',')
			if(!ft_strncmp(&nptr[idx], ",0x", 3))
			return (idx + 3);
		idx++;
	}
	return (0);
}