/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:47:16 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 12:52:32 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char str1;
    unsigned char str2;
    size_t i;

    str1 = (unsigned char) *s1;
    str2 = (unsigned char) *s2;

    while(i < n)
    {
        if(str1[i] != str2[i])
        {
            return (str1[i] - str2[i])
        }
        i++;
    }
    return (0);
}
