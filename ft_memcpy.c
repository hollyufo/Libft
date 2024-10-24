/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:19:20 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/24 09:44:59 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *temp_dst;
    unsigned char *temp_src;
    
    if (!dst && !src) {
        return dst;
    }
    
    temp_dst = (unsigned char *)dst;
    temp_src = (unsigned char *)src;
    
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src++);
        n--;
	}
	return temp_dst;
}