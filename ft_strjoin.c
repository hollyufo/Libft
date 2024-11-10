/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:58:16 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/10 23:37:12 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	p_strlen(const char *str)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

static char	*allocate_and_copy(const char *src, size_t len)
{
	char	*result;

	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (result)
		ft_strlcpy(result, src, len + 1);
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str_result;

	if (!s1 && !s2)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (!s1)
		return (allocate_and_copy(s2, p_strlen(s2)));
	if (!s2)
		return (allocate_and_copy(s1, p_strlen(s1)));
	s1_len = p_strlen(s1);
	s2_len = p_strlen(s2);
	str_result = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!str_result)
		return (NULL);
	ft_strlcpy(str_result, s1, s1_len + 1);
	ft_strlcpy(str_result + s1_len, s2, s2_len + 1);
	return (str_result);
}
