/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:19:20 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/23 17:02:58 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *temp_dst;
    unsigned char *temp_src;
    size_t i;
    
    if (!dst && !src) {
        return dst;
    }
    
    temp_dst = (unsigned char *)dst;
    temp_src = (unsigned char *)src;
    i = 0;
    
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src++);
        n--;
	}
	return temp_dst;
}