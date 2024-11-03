/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:50:08 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 14:33:39 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int countDigit(long long num)
{
    int count = 0;

    if (num == 0)
        return 1;

    if (num < 0)
        num = -num;

    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

char *ft_itoa(int n)
{
    int len = countDigit(n);
    int is_negative = (n < 0);
    if (is_negative)
        len++;

    char *str = (char *)ft_calloc(len + 1, sizeof(char));
    if (!str)
        return NULL;

    if (n == 0)
    {
        str[0] = '0';
        return str;
    }

    if (is_negative)
        n = -n;
    str[len] = '\0';
    
    while (n != 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    if (is_negative)
        str[0] = '-';

    return str;
}
