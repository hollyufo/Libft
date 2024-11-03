/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:58:16 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 14:34:16 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *str);

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t s1_len = s1 ? ft_strlen(s1) : 0;
    size_t s2_len = s2 ? ft_strlen(s2) : 0;
    
    if (!s1 && !s2)
    {
        return (char *)ft_calloc(1, sizeof(char));
    }

    if (!s1)
    {
        char *result = (char *)ft_calloc(s2_len + 1, sizeof(char));
        if (result)
        {
            ft_strlcpy(result, s2, s2_len + 1);
        }
        return result;
    }

    if (!s2)
    {
        char *result = (char *)ft_calloc(s1_len + 1, sizeof(char));
        if (result)
        {
            ft_strlcpy(result, s1, s1_len + 1);
        }
        return result;
    }

    char *str_result = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
    if (!str_result)
    {
        return NULL;
    }

    ft_strlcpy(str_result, s1, s1_len + 1);
    ft_strlcpy(str_result + s1_len, s2, s2_len + 1);

    return str_result;
}