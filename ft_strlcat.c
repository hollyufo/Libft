/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:13:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:51:22 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str);

size_t ft_strlcat(char *dst, const char *src, size_t dstsize) {
    size_t dst_len = 0;
    size_t src_len = ft_strlen(src);
    size_t i = 0;

    while (dst[dst_len] != '\0' && dst_len < dstsize) {
        dst_len++;
    }

    if (dst_len >= dstsize) {
        return dstsize + src_len;
    }

    size_t space_left = dstsize - dst_len - 1;

    while (i < space_left && src[i] != '\0') {
        dst[dst_len + i] = src[i];
        i++;
    }

    dst[dst_len + i] = '\0';

    return dst_len + src_len;
}
