/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hollyufo <hollyufo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:50:08 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/06 14:39:34 by hollyufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	count_digit(long long num)
{
	int	count = 0;

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
	if (len == 1) // This ensures zero for cases like -2147483648
		str[0] = '0';
}

char	*ft_itoa(int n)
{
	long long	num = n; // Use a long long to handle edge cases
	int			len;
	char		*str;

	len = count_digit(num) + (n < 0 ? 1 : 0);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);

	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	fill_number_str(str, num, len);
	if (n < 0)
		str[0] = '-';
	return (str);
}
