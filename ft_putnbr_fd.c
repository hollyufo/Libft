/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:28:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 15:29:55 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int fd, int nb)
{
	long int	num;

	num = nb;
	if (num < 0)
	{
		ft_putchar_fd(fd,'-');
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(fd, num / 10);
	}
	ft_putchar_fd(fd, (num % 10) + '0');
}