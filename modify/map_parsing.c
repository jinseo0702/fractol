#include "../include/fractol.h"
//this version is  check malloc t_value before problem is allocated appropriately
//so make error but modify
//check printf comment.

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

t_value ***alc_map(int high, int width)//3차원 배열을 free해주는 건 아직 만들지 않음
{
	int idx;
	int idx2;
	t_value ***value;

	idx = -1;
	value = (t_value ***)malloc(sizeof(t_value **) * (high + 1));
	if (!value)
		ft_error("not allocated malloc");
	while (++idx < high)
	{
		value[idx] = (t_value **)malloc(sizeof(t_value *) * (width + 1));
		if (!&value[idx])
			ft_error("not allocated malloc");//이부분은 누수관리가 필요함.
		idx2 = -1;
		while(++idx2 < width)
		{
			value[idx][idx2] = (t_value *)malloc(sizeof(t_value) * (width + 1));
			if (!&value[idx][idx2])
				ft_error("not allocated malloc");
			init_value(value[idx][idx2]);
		}
		printf("alc map idx2 %d \n", idx2);//에러내용 메모리를 할당할때 알맞게 해서 문제가 생긴다. + 1씩 더해 주자
	}
	return (value);
}

void map_parsing(t_value ***value, char *str, t_map *map)
{
	int fd;
	int idx1;
	int idx2;
	char *temp;
	char **two;

	if ((fd = open(str, O_RDONLY)) < 0)
		ft_error("file is not open! retry");
	idx1 = 0;
	while ((temp = get_next_line(fd)))
	{
		idx2 = 0;
		two = ft_split(temp, ' ');
		while (two[idx1] && idx2 < map->width)
		{
			printf("%d, idx2 %d \n", value[idx1][idx2]->x, idx2);
			value[idx1][idx2]->x = idx2;
			value[idx1][idx2]->y = idx1;
			value[idx1][idx2]->z = ft_atoi(two[idx1]);//색 표현은 아직 만지지 않았음 추가해야함
			value[idx1][idx2]->color = NULL;
			idx2++;
		}
		free_two_arry(two, NULL, 2);
		free_two_arry(NULL, temp, 1);
		idx1++;
	}
	close(fd);
}