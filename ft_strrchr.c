/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:22:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:52:23 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strrchr(const char *s, int c) {
    char char_to_find = (char)c;
    char *result = NULL;  // Initialize result to NULL

    // Iterate through the string to find the last occurrence of char_to_find
    while (*s != '\0') {
        if (*s == char_to_find) {
            result = (char *)s;
        }
        s++;
    }

    // Check if the null terminator matches char_to_find
    if (char_to_find == '\0') {
        return (char *)s;
    }

    return result;
}
