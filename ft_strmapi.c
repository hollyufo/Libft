/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:45:29 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 15:01:47 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    size_t i;
    
    i = 0;
    if (!s || !f)
        return NULL;

    size_t len = 0;
    while (s[len] != '\0')
        len++;
        
    char *new_str = (char *)malloc((len + 1) * sizeof(char));
    if (!new_str)
        return NULL;

    while (i < len)
    {
        new_str[i] = f(i, s[i]);
        i++;
    }
    new_str[len] = '\0';

    return new_str;
}
