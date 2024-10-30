#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

// Set memory to zero
void ft_bzero(void *s, size_t n)
{
    unsigned char *p = (unsigned char *)s;
    size_t i = 0;

    while (i < n)
    {
        p[i] = 0;
        i++;
    }
}

// Allocate and zero-initialize memory
void *ft_calloc(size_t count, size_t size)
{
    void *temp_str;
    size_t total_size;

    if (count == 0 || size == 0)
    {
        return malloc(0);
    }

    // Check for overflow
    if (count > SIZE_MAX / size)
    {
        return NULL;
    }

    total_size = count * size;
    temp_str = malloc(total_size);

    if (!temp_str)
    {
        return NULL;
    }

    ft_bzero(temp_str, total_size);

    return temp_str;
}

// Calculate the length of a string, returning 0 for NULL strings
size_t ft_strlen(const char *str)
{
    if (!str)
    {
        return 0;
    }

    size_t i = 0;
    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

// Copy string from src to dst, ensuring null-termination and size limit
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i = 0;
    size_t src_len = ft_strlen(src);

    if (dstsize > 0)
    {
        while (i < dstsize - 1 && src[i] != '\0')
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';  // Null-terminate the destination string
    }

    return src_len;  // Return the length of the source string
}

// Concatenate two strings into a new string
char *ft_strjoin(char const *s1, char const *s2)
{
    size_t s1_len = s1 ? ft_strlen(s1) : 0;
    size_t s2_len = s2 ? ft_strlen(s2) : 0;
    
    // If both are NULL, return an empty string
    if (!s1 && !s2)
    {
        return (char *)ft_calloc(1, sizeof(char));
    }

    // If s1 is NULL, return a copy of s2
    if (!s1)
    {
        char *result = (char *)ft_calloc(s2_len + 1, sizeof(char));
        if (result)
        {
            ft_strlcpy(result, s2, s2_len + 1);
        }
        return result;
    }

    // If s2 is NULL, return a copy of s1
    if (!s2)
    {
        char *result = (char *)ft_calloc(s1_len + 1, sizeof(char));
        if (result)
        {
            ft_strlcpy(result, s1, s1_len + 1);
        }
        return result;
    }

    // Allocate memory for the concatenated string
    char *str_result = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
    if (!str_result)
    {
        return NULL;
    }

    // Copy s1 to str_result
    ft_strlcpy(str_result, s1, s1_len + 1);
    // Concatenate s2 to str_result
    ft_strlcpy(str_result + s1_len, s2, s2_len + 1);

    return str_result;
}

// Test function for ft_strjoin
void test_ft_strjoin(const char *s1, const char *s2, const char *expected)
{
    char *result = ft_strjoin(s1, s2);
    if ((result == NULL && expected == NULL) || (result && expected && strcmp(result, expected) == 0))
    {
        printf("PASS: '%s' + '%s' -> '%s'\n", s1 ? s1 : "(null)", s2 ? s2 : "(null)", expected ? expected : "(null)");
    }
    else
    {
        printf("FAIL: '%s' + '%s' -> Expected: '%s', Got: '%s'\n", s1 ? s1 : "(null)", s2 ? s2 : "(null)", expected ? expected : "(null)", result ? result : "(null)");
    }
    free(result);  // Free allocated memory
}

int main(void)
{
    // Test cases for ft_strjoin
    test_ft_strjoin("Hello", " World", "Hello World");
    test_ft_strjoin("", "World", "World");
    test_ft_strjoin("Hello", "", "Hello");
    test_ft_strjoin("", "", "");
    test_ft_strjoin("42", "Network", "42Network");
    test_ft_strjoin(NULL, "Hello", "Hello");  // NULL input
    test_ft_strjoin("Hello", NULL, "Hello");  // NULL input
    test_ft_strjoin(NULL, NULL, "");          // Both NULL

    return 0;
}
