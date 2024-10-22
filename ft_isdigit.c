#include <unistd.h>

int ft_isdigit(int num)
{
    if (num >= 0 && num <= 9)
    {
        return (1);
    }
    return (0);
}
