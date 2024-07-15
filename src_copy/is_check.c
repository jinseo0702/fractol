#include "../include/fractol.h"

void is_vaild(char *str, int fd)
{
	char *temp;

	if((temp = ft_strrchr(str, '.')) == 0)
	{
		close(fd);
		ft_error("umm.... inputfile is not fdf try again");
	}
	if (!ft_strncmp(temp, ".fdf", 4) && ft_strlen(temp) == 4)
		return ;
	else
	{
		close(fd);
		ft_error("umm.... inputfile is not fdf try again");
	}
}