/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:13:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/10 23:37:20 by imchaibi         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	space_left;

	if (!dst || !src)
		return (0);
	dst_len = 0;
	src_len = p_strlen(src);
	i = 0;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
		dst_len++;
	if (dst_len >= dstsize)
	{
		return (dstsize + src_len);
	}
	space_left = dstsize - dst_len - 1;
	while (i < space_left && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
