/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:13:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/24 14:36:35 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dst_len;
    size_t src_len;
    size_t space_left;
    size_t i;
    src_len = ft_strlen(src);
    while (dst[dst_len] != '\0' && dst_len < dstsize)
    {
        dst_len++;
    }
    if(dst_len >= dstsize)
    {
        return (dst_len + src_len);
    }
    
    space_left = dstsize - dst_len - 1;
    
    while(i < space_left && src[i] = '\0')
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    
    dst[i] = '\0';
    return (dst_len + src_len)
}