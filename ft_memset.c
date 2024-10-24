/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:04:07 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/23 14:31:44 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *p = (unsigned char *)s;
    
    size_t i;

    i = 0;
    while (i < n)
    {
        p[i] = c;
        i++;
    }
    
    return s;
}
