/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:17:09 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 17:58:37 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp_str;
	size_t	total_size;

	if (count == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (count > SIZE_MAX / size)
	{
		return (NULL);
	}
	total_size = count * size;
	temp_str = malloc(total_size);
	if (!temp_str)
	{
		return (NULL);
	}
	ft_bzero(temp_str, total_size);
	return (temp_str);
}
