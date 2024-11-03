/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:44:17 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 18:35:16 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char delimiter)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
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
	return (count);
}

static char	*allocate_word(const char *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

char **ft_split(const char *s, char c)
{
    if (!s)
        return NULL;

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
