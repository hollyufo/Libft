/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:50:18 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/27 12:55:21 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t ft_strlen(const char *str);

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)

char *ft_strdup(const char *src)
{
    size_t len = ft_strlen(src);
    char *dub = (char *)malloc((len + 1) * sizeof(char));

    if (dub == NULL)
    {
        return NULL;
    }

    ft_strlcpy(dub, src, len + 1);
    return dub;
}