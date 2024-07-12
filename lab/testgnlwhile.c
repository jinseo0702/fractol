#include "../include/fractol.h"


int main(int argc, char **argv)
{
	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	char *str;
	int line = 0;
	while ((str =get_next_line(fd)))
	{
		free(str);
		line++;
	}
	printf("line is %d\n", line);
	return (0);
}//이결과로 보시다시피 leak도안나는걸 볼 수 있습니다. line의 줄수는 이렇게 count하면됩니다.