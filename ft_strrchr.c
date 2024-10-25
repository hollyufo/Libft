/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:22:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/25 13:47:00 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <unistd.h>

char *ft_strrchr(const char *s, int c)
{
    int i;
    char char_to_find;
    char result;

    char_to_find = (char) c;
    i = 0;
    
    while(s[i])
    {
        if(s[i] == char_to_find)
        {
            result = (char *) &s[i];
        }
        i++;
    }
    if (s[i] == char_to_find)
    {
        result = (char *) &s[i];
    }
    return (result);
}