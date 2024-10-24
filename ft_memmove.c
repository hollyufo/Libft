/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:05:55 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/24 09:45:11 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *temp_dst;
    unsigned char *temp_src;
    
    if (!dst && !src)
    {
        return dst;
    }

    temp_dst = (unsigned char *)dst;
    temp_src = (unsigned char *)src;

    if (temp_src < temp_dst && (temp_src + n) > temp_dst)
    {
        // copy backwards as the mem overlaps 
        temp_dst += n - 1;
        temp_src += n - 1;
        while (n--) {
            *temp_dst-- = *temp_src--;
        }
    }
    else 
    {
        // No overlap copy normally
        while (n--)
        {
            *temp_dst++ = *temp_src++;
        }
    }
    
    return dst;
}