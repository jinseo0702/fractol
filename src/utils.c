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

void ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}