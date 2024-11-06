/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:50:08 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/06 15:42:03 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	count_digit(long long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num = -num;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static void	fill_number_str(char *str, long long num, int len)
{
	str[len] = '\0';
	if (num < 0)
		num = -num;
	while (len > 0 && num != 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (len == 1)
		str[0] = '0';
}

char	*ft_itoa(int n)
{
	long long	num;
	int			len;
	char		*str;
	int			isnegative;

	num = n;
	isnegative = 0;
	if (n < 0)
		isnegative = 1;
	len = count_digit(num) + isnegative;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	fill_number_str(str, num, len);
	if (isnegative)
	{
		str[0] = '-';
	}
	return (str);
}
