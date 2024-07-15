#include "../include/fractol.h"


int main(void)
{
	char *arr = "0123456789abcdef";

	printf("%ld \n", (ft_strchr(arr, '0') - arr));
	return (0);
}