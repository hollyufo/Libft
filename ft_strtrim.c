/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:22:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/31 13:30:29 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>



static int is_in_set(char c, const char *set)
{
    int i = 0;
    while (set[i])
    {
        if (c == set[i])
        {
            return (1);
        }
        
        i++;
    }
    return (0);
}

void *ft_strtrim(char const *s1, char const *set)
{
    size_t start = 0;
    size_t end = ft_strlen(s1) - 1;
    char *trimmed_str;
    
    while(s1[start] && is_in_set(s1[start], set))
    {
        start++;
    }
    while (end >= start && is_in_set(s1[end], set))
    {
        end--;
    }
    // If start is beyond end, return an empty string
    if (start > end)
        return ft_calloc(1, sizeof(char));

    // Use ft_substr to get the trimmed substring
    trimmed_str = ft_substr(s1, start, end - start + 1);
    return trimmed_str;
}
