/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:48:16 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 14:34:23 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *str);

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t src_len;

    src_len = ft_strlen(src);
    i = 0;

    if (dstsize > 0)
    {
        // Copy up to dstsize - 1 characters from src to dst
        while (i < dstsize - 1 && src[i] != '\0')
        {
            dst[i] = src[i];
            i++;
        }
        // Null-terminate the destination string
        dst[i] = '\0';
    }

    return src_len;  // Return the length of the source string
}
