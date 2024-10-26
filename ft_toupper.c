/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:38:40 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:45:49 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_toupper(int c) {
    if (c >= 'a' && c <= 'z') {
        return (c - 32);  
    }
    return c;
}
#include <stdio.h>
#include <ctype.h>

// Declaration of your custom ft_toupper function
int ft_toupper(int c);

// Function to run test cases
void run_tests() {
    // Iterate through all possible ASCII characters (0 to 127)
    for (int i = 0; i <= 127; i++) {
        // Call ft_toupper and toupper for each character
        int result_ft = ft_toupper(i);
        int result_std = toupper(i);

        // Compare results
        if (result_ft != result_std) {
            printf("Mismatch: char='%c' (ASCII=%d) | ft_toupper=%d, toupper=%d\n", 
                   i, i, result_ft, result_std);
        } else {
            printf("Match: char='%c' (ASCII=%d) | Result=%d\n", 
                   i, i, result_ft);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}