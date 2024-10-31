/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:44:17 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/31 14:16:58 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *p = (unsigned char *)s;
    
    size_t i;

    i = 0;
    while (i < n)
    {
        p[i] = c;
        i++;
    }
    
    return s;
}

void ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}
int count_words(const char *str, char delimiter)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str != delimiter)
        {
            if (!in_word)
            {
                in_word = 1;
                count++;
            }
        }
        else
        {
            in_word = 0;
        }
        str++;
    }

    return count;
}
void ft_bzero(void *s, size_t n);

void *ft_calloc(size_t count, size_t size)
{
    void *temp_str;
    size_t total_size;

    
    if (count == 0 || size == 0)
    {
        return malloc(0);
    }
    // checking over flow
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
// Allocate memory for each word
static char *allocate_word(const char *s, char c)
{
    int len = 0;
    while (s[len] && s[len] != c)
        len++;
    
    char *word = (char *)ft_calloc(len + 1, sizeof(char)); // Using `ft_calloc`
    if (!word)
        return NULL;
    
    for (int i = 0; i < len; i++)
        word[i] = s[i];
    
    return word;
}

// Split function
char **ft_split(const char *s, char c)
{
    if (!s)
        return NULL; // NULL input returns NULL

    int word_count = count_words(s, c);
    
    // Handle empty string and only delimiters case
    if (word_count == 0)
    {
        char **empty_result = (char **)ft_calloc(2, sizeof(char *));
        if (!empty_result)
            return NULL;
        empty_result[0] = ft_calloc(1, sizeof(char)); // Empty string entry
        return empty_result;
    }

    char **result = (char **)ft_calloc(word_count + 1, sizeof(char *)); // Null-terminated array
    if (!result)
        return NULL;

    int i = 0;
    while (*s)
    {
        if (*s != c)
        {
            result[i] = allocate_word(s, c);
            if (!result[i])
            {
                while (i > 0) // Free previously allocated memory on failure
                    free(result[--i]);
                free(result);
                return NULL;
            }
            i++;
            while (*s && *s != c)
                s++;
        }
        else
        {
            s++;
        }
    }
    return result;
}

// Custom free function to free the split array
void ft_free_split(char **arr)
{
    if (!arr)
        return;

    int i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

// Test function
void test_ft_split(const char *str, char delimiter)
{
    char **result = ft_split(str, delimiter);
    if (!result)
    {
        printf("Memory allocation failed or NULL input\n");
        return;
    }

    int i = 0;
    while (result[i])
    {
        printf("Word %d: '%s'\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
}

int main()
{
    // Edge case tests
    test_ft_split(NULL, ' '); // NULL input
    test_ft_split("", ' '); // Empty string
    test_ft_split(",,,,", ','); // Only delimiters
    test_ft_split("Hello", ' '); // Single word, no delimiters
    test_ft_split("H", 'H'); // Single character matching delimiter
    test_ft_split("A", ' '); // Single character, non-matching delimiter
    test_ft_split("Hello World", ' '); // Regular split
    test_ft_split(",,,Hello,,,World,,,", ','); // Leading, trailing, and consecutive delimiters
    
    return 0;
}