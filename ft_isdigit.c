/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:36:12 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/22 13:54:08 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isdigit(int num)
{
	if (num >= 0 && num <= 9)
	{
		return (1);
	}
	return (0);
}
