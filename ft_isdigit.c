/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:36:12 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:43:55 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int num)
{
	if (num >= 0 && num <= 9)
	{
		return (1);
	}
	return (0);
}


// Function to run test cases
void run_tests() {
    // Iterate through all possible ASCII characters (0 to 127)
    for (int i = 0; i <= 127; i++) {
        // Compare ft_isdigit with isdigit for each character
        int result_ft = ft_isdigit(i);
        int result_std = isdigit(i);
        
        // Print mismatch if results differ
        if (result_ft != result_std) {
            printf("Mismatch: Char='%c' (ASCII=%d) | ft_isdigit=%d, isdigit=%d\n", 
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