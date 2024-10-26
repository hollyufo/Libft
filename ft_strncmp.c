/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:50:10 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:45:18 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;

    while((s1[i] || s1[i]) && i < n)
    {
        if((unsigned char) s1[i] != (unsigned char) s2[i])
        {
            return ((unsigned char) s1[i] - (unsigned char) s2[i]);
        }
        i++;
    }
    return (0);
}

#include <stdio.h>
#include <string.h>

// Declaration of your custom strncmp function
int ft_strncmp(const char *s1, const char *s2, size_t n);

// Function to run test cases
void run_tests() {
    // Test strings
    char *str1 = "Hello, World!";
    char *str2 = "Hello, Universe!";
    char *str3 = "Hello";
    char *str4 = "Hell";
    char *str5 = "Heaven";
    char *str6 = "";
    char *str7 = "Different";

    // Test parameters: string1, string2, and number of characters to compare
    struct {
        char *s1;
        char *s2;
        size_t n;
    } test_cases[] = {
        {str1, str2, 7},   // Matching initial segment, different after
        {str1, str3, 5},   // Exact match
        {str1, str4, 4},   // Partial match
        {str3, str5, 2},   // Match at the start
        {str3, str5, 5},   // No match
        {str6, str6, 1},   // Empty strings
        {str1, str6, 5},   // One empty string
        {str7, str7, 9},   // Identical strings
        {str7, str1, 0},   // Zero length comparison
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        char *s1 = test_cases[i].s1;
        char *s2 = test_cases[i].s2;
        size_t n = test_cases[i].n;

        // Call ft_strncmp and strncmp
        int result_ft = ft_strncmp(s1, s2, n);
        int result_std = strncmp(s1, s2, n);

        // Compare results
        if (result_ft != result_std) {
            printf("Mismatch: s1='%s', s2='%s', n=%zu | ft_strncmp=%d, strncmp=%d\n", 
                   s1, s2, n, result_ft, result_std);
        } else {
            printf("Match: s1='%s', s2='%s', n=%zu | Result=%d\n", s1, s2, n, result_ft);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}