/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:55:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/27 15:18:35 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strdup(const char *src);

size_t ft_strlen(const char *str);

void *ft_calloc(size_t count, size_t size);

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t str_len;
    size_t sub_len;
    char *substr;

    if (!s)
    {
        return NULL;
    }

    str_len = ft_strlen(s);

    if (start >= str_len)
    {
        return ft_calloc(1, sizeof(char));
    }

    sub_len = (str_len - start < len) ? (str_len - start) : len;

    substr = (char *)ft_calloc(sub_len + 1, sizeof(char));
    if (!substr)
    {
        return NULL;
    }
    
    ft_strlcpy(substr, s + start, sub_len + 1);

    return substr;
}
