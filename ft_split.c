/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hollyufo <hollyufo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:44:17 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/06 14:38:39 by hollyufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char delimiter)
{
	int	count = 0;
	int	in_word = 0;

	while (*str)
	{
		if (*str != delimiter && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*str == delimiter)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*allocate_word(const char *s, char c)
{
	int		len = 0;
	char	*word;
	int		i = 0;

	// Find the length of the word
	while (s[len] && s[len] != c)
		len++;
	// Allocate memory for the word
	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	// Copy the word into the allocated space
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**free_split(char **result, int i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		word_count;
	char	**result;
	int		i = 0;

	if (!s)
		return (NULL);

	word_count = count_words(s, c);
	// Allocate memory for the result array, with an extra slot for NULL termination
	result = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!result)
		return (NULL);

	while (i < word_count)
	{
		// Skip delimiters to the start of the next word
		while (*s == c)
			s++;
		// Allocate and copy the word into the result array
		result[i] = allocate_word(s, c);
		if (!result[i])
			return (free_split(result, i)); // Free everything if allocation fails
		// Move the pointer to the end of the current word
		while (*s && *s != c)
			s++;
		i++;
	}
	result[i] = NULL; // NULL terminate the array
	return (result);
}