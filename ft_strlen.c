/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:56:25 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/22 16:14:20 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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