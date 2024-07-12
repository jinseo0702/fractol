#include "../include/fractol.h"

int main(int argc, char **argv)
{
	(void)argc;

	int fd = open(argv[1], O_RDONLY);
	static char buff[100];
	read(fd, &buff, 100);
	printf("%sand %d \n", buff, fd);
	close(fd);
	int fd2 = open(argv[1], O_RDONLY);
	static char buff2[100];
	read(fd2, &buff2, 100);
	printf("%sand %d \n", buff2, fd2);
	close(fd2);
	return (0);
}//이걸로 알수 있는 사실은 open하고 close를 하고 다시열면 파일포인터는 초기화 된다.
//이걸로 할 수 있는 것은 gnl로라인의 수를 알 수 있다.