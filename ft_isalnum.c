/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:36:04 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/22 13:38:54 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unisted.h>

int ft_isalnum(int c)
{
if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || (c >= 0 && c <= 9))
{
return (1);
}
return (0);
}
