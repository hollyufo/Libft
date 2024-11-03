/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:25:06 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/03 15:27:49 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void    ft_putendl_fd(char *str, int fd)
{
    if (!str)
        return;

    size_t i = 0;
    while (str[i])
        i++;

    write(fd, str, i);
    write(fd, "\n", 1);
}