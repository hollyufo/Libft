/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:22:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 23:28:31 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	char_to_find;
	char	*result;

	char_to_find = (char)c;
	result = NULL;
	while (*s != '\0')
	{
		if (*s == char_to_find)
		{
			result = (char *)s;
		}
		s++;
	}
	if (char_to_find == '\0')
	{
		return ((char *)s);
	}
	return (result);
}
