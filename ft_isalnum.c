/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:36:04 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:43:28 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int ft_isalnum(int c)
{
    if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || (c >= 0 && c <= 9))
    {
        return (1);
    }
    return (0);
}

void run_tests() {
    // Iterate through all possible ASCII characters (0 to 127)
    for (int i = 0; i <= 127; i++) {
        // Compare ft_isalnum with isalnum for each character
        int result_ft = ft_isalnum(i);
        int result_std = isalnum(i);
        
        // Print mismatch if results differ
        if (result_ft != result_std) {
            printf("Mismatch: Char='%c' (ASCII=%d) | ft_isalnum=%d, isalnum=%d\n", 
                   (char)i, i, result_ft, result_std);
        } else {
            printf("Match: Char='%c' (ASCII=%d) | Result=%d\n", 
                   (char)i, i, result_ft);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}