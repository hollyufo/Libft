/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:17:09 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:49:53 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void *ft_calloc(size_t count, size_t size)
{
    unsigned char *temp_str;
    size_t i;
    
    i = 0;
    temp_str = malloc(count * size);
    
    if(!temp_str)
    {
        return (NULL);
    }
    while (i < count * size)
    {
        temp_str[i] = 0;
        i++;
    }
    
    return (temp_str);
}
