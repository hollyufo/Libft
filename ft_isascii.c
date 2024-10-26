/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:41:52 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:43:49 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

// Function to run test cases
void run_tests() {
    // Iterate through all possible ASCII and extended ASCII characters (0 to 255)
    for (int i = 0; i <= 255; i++) {
        // Compare ft_isascii with isascii for each character
        int result_ft = ft_isascii(i);
        int result_std = isascii(i);
        
        // Print mismatch if results differ
        if (result_ft != result_std) {
            printf("Mismatch: Char='%c' (ASCII=%d) | ft_isascii=%d, isascii=%d\n", 
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