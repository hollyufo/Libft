/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:44:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/27 13:02:49 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void ft_bzero(void *s, size_t n)
{
    unsigned char *p = (unsigned char *)s;
    size_t i;

    i = 0;
    while (i < n)
    {
        p[i] = 0;
        i++;
    }
}

