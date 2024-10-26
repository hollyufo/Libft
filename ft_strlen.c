/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:56:25 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:45:07 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}
void run_tests() {
    // Test strings
    char str1[] = "Hello, World!";
    char str2[] = "1234567890";
    char str3[] = "";
    char str4[] = "This is a longer test string.";
    char *str5 = NULL; // Intentional NULL pointer for segmentation fault test

    // Test cases: different strings, including NULL
    char *test_cases[] = {
        str1,
        str2,
        str3,
        str4,
        str5 // This will cause a segmentation fault
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        char *str = test_cases[i];

        // Handle NULL pointer separately
        if (str == NULL) {
            printf("\n--- Intentional NULL pointer test ---\n");
            printf("Expecting a segmentation fault...\n");
            // Uncomment the following line to actually cause a segmentation fault
            // size_t len_ft = ft_strlen(str); 
            // printf("ft_strlen(NULL) = %zu\n", len_ft);
            continue;
        }

        // Call ft_strlen and strlen
        size_t len_ft = ft_strlen(str);
        size_t len_std = strlen(str);

        // Compare results
        if (len_ft != len_std) {
            printf("Mismatch: String='%s' | ft_strlen=%zu, strlen=%zu\n", str, len_ft, len_std);
        } else {
            printf("Match: String='%s' | Length=%zu\n", str, len_ft);
        }
    }

}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}