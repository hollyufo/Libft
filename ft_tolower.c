/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:43:50 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:45:44 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_tolower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return (c + 32);
    }
    return c;
}
void run_tests() {
    // Iterate through all possible ASCII characters (0 to 127)
    for (int i = 0; i <= 127; i++) {
        // Call ft_tolower and tolower for each character
        int result_ft = ft_tolower(i);
        int result_std = tolower(i);

        // Compare results
        if (result_ft != result_std) {
            printf("Mismatch: char='%c' (ASCII=%d) | ft_tolower=%d, tolower=%d\n", 
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