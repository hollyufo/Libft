/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:22:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:52:23 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}


int is_in_set(char c, const char *set)
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
    size_t i;
    printf("the len is %li \n", end);
    
    while(s1[start] && is_in_set(s1[start], set))
    {
        printf("start index is %c\n", s1[start]);
        start++;
    }
    i = start;
    while (end >= start && is_in_set(s1[end], set))
    {
        printf(" end index is %c\n", s1[end]);
        end--;
    }
    printf("start is %li \n", start);
    printf("end is %li \n", end);
    while (i >= end)
    {
        printf("end is %c \n", s1[i]);
        i++;
    }
    printf("\n");
    return 0;
}

int main()
{
    const char s1[] = "ababaaaMy name is Simonbbaaabba";
    const char set[] = "ab";
    ft_strtrim(s1, set);
}