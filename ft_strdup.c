/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:50:18 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 14:34:06 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *src)
{
    size_t len = ft_strlen(src);
    char *dub = (char *)ft_calloc(len + 1, sizeof(char));

    if (dub == NULL)
    {
        return NULL;
    }

    ft_strlcpy(dub, src, len + 1);
    return dub;
}