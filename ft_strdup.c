/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:50:18 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/10 23:36:51 by imchaibi         ###   ########.fr       */
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

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dub;

	if (src == NULL)
	{
		dub = (char *)ft_calloc(1, sizeof(char));
		if (dub == NULL)
			return (NULL);
		return (dub);
	}
	len = p_strlen(src);
	dub = (char *)ft_calloc(len + 1, sizeof(char));
	if (dub == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(dub, src, len + 1);
	return (dub);
}
