/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:19:20 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/09 16:05:01 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
	{
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;

	if (!dst || !src)
	{
		return (NULL);
	}
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (n > 0)
	{
		*(temp_dst++) = *(temp_src++);
		n--;
	}
	return (dst);
}
