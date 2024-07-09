#include "../include/fractol.h"

void init_arry(t_map map[860][540])
{
    static int high;
    static int len;

    while (high < 860)
    {
        while (len < 540)
        {
            map[high][len].x = 0; 
            map[high][len].y = 0;
            map[high][len].z = 0;
            map[high][len].color = NULL; 
            len++;
        }
        high++;
    }
}

void passing_map(t_map map[860][540], int fd)
{
    int high = 0;
    int len = 0;
    char *str  = get_next_line(fd);
    char **split_char;

    init_arry(map);
    while (str)
    {
        len = 0;
        split_char = ft_split(str, ' ');
        while (split_char[len])
        {
            map[high][len].x = high;
            map[high][len].y = len;
            map[high][len].z = ft_atoi(split_char[len]);
            len++;
        }
        ft_strfree(split_char, len);
        free(str);
        high++;
        str = get_next_line(fd);
    }
}

void	ft_strfree(char **split_argv, int idx)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (size < idx)
	{
		free(split_argv[i]);
		i++;
		size++;
	}
	free(split_argv);
	split_argv = NULL;
}

int main(int argc, char **argv)
{
    t_map map[860][540];
    int fd;

    ft_strlen(argv[1]);
    if (argc == 2 && ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
    {
        fd = open(argv[1], O_RDONLY);
        passing_map(map, fd);
        ft_printf("clear!\n");
    }
    return (0);
}