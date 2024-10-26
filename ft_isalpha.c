/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:36:09 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:43:40 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return (1);
    }
    return (0);
}

// Function to run test cases
void run_tests() {
    // Iterate through all possible ASCII characters (0 to 127)
    for (int i = 0; i <= 127; i++) {
        // Compare ft_isalpha with isalpha for each character
        int result_ft = ft_isalpha(i);
        int result_std = isalpha(i);
        
        // Print mismatch if results differ
        if (result_ft != result_std) {
            printf("Mismatch: Char='%c' (ASCII=%d) | ft_isalpha=%d, isalpha=%d\n", 
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
