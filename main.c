#include <stdio.h>

int ft_atoi(const char *str);

int main()
{
	int i = 0;

	i = ft_atoi("2147483650");
	printf("%d\n", atoi("2147483650"));
	printf("%d",i);
}
