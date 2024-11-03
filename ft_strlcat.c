/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:13:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 22:22:07 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	space_left;

	dst_len = 0;
	src_len = ft_strlen(src);
	i = 0;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
	{
		dst_len++;
	}
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
