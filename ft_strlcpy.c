/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:48:16 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/24 14:22:54 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t ft_strlen(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t src_len;
    
    src_len = ft_strlen(src);
    
    if(dstsize > 0)
    {
        while(i < dstsize - 1 && src[i] != '\0')
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return src_len;
}
