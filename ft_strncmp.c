/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:50:10 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/25 13:53:14 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;

    i = 0;

    while(s1[i] || s1[i] && i < n)
    {
        if((unsigned char) s1[i] != (unsigned char) s2[i])
        {
            return ((unsigned char) s1[i] - (unsigned char) s2[i]);
        }
        i++;
    }
    return (0);
}
    