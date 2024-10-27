/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:55:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/27 12:46:59 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t i;
    char *str;
    
    if(!s)
    {
        return (NULL);
    }
    if(ft_strlen(s) > start)
    {
        
    }
}
