/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:22:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:45:35 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

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
// Function to run test cases
void run_tests() {
    // Test strings
    char *str1 = "Hello, World!";
    char *str2 = "abcdefabcdef";
    char *str3 = "aaaaa";
    char *str4 = "12345";
    char *str5 = "";
    char *str6 = "End of string";
    char *str7 = "No matches";

    // Test characters to find
    int chars_to_find[] = {
        'o',   // Multiple occurrences
        'f',   // Multiple occurrences
        'a',   // All same characters
        '5',   // Single match
        'x',   // No match
        '\0',  // Null terminator
        'N'    // Single occurrence at start
    };

    // Test parameters: string and character to find
    struct {
        char *str;
        int c;
    } test_cases[] = {
        {str1, chars_to_find[0]},
        {str2, chars_to_find[1]},
        {str3, chars_to_find[2]},
        {str4, chars_to_find[3]},
        {str5, chars_to_find[4]},
        {str6, chars_to_find[5]},
        {str7, chars_to_find[6]},
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        char *str = test_cases[i].str;
        int c = test_cases[i].c;

        // Call ft_strrchr and strrchr
        char *result_ft = ft_strrchr(str, c);
        char *result_std = strrchr(str, c);

        // Compare results
        if (result_ft != result_std) {
            printf("Mismatch: str='%s', char='%c' | ft_strrchr=%p, strrchr=%p\n", 
                   str, c, result_ft, result_std);
        } else {
            printf("Match: str='%s', char='%c' | Result=%p\n", str, c, result_ft);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}