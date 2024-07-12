#include "../include/fractol.h"


int main(int argc, char **argv)
{
	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	int cnt;
	char *str;
	char **two;
	while ((str =get_next_line(fd)))
	{
		cnt = 0;
		two = ft_split(str, ' ');
		while (two[cnt])
			cnt++;
		free(str);
		printf("width is %d\n", cnt);
	}
	return (0);
}