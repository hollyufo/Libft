#include <unisted.h>

int isalnum(int)
{
    if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || (num >= 0 && num <= 9))
    {
        return (1);
    }
    return (0);
}