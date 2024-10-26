/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:05:24 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:50:28 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *str;
    unsigned char c_to_find;
    size_t i;

    str = (unsigned char *) s;
    c_to_find = (unsigned char) c;
    i = 0;

    while (i < n)
    {
        if(str[i] == c_to_find)
        {
            return ((void *) &str[i]);
        }
        i++;
    }
    return (NULL);
}
