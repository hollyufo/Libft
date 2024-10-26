/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:52:10 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:45:27 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;
    
    i = 0;
    j = 0;
    
    if (*needle == '\0')
    {
        return (char *)haystack;
    }

    while (haystack[i] != '\0' && i < len)
    {
        j = 0;
        while (haystack[i + j] == needle[j] && (i + j) < len)
        {
            if (needle[j + 1] == '\0') {
                return (char *)(haystack + i);
            }
            j++;
        }
        i++;
    }
    
    return NULL;
}
void run_tests() {
    // Test haystacks and needles
    char *haystack1 = "Hello, World!";
    char *needle1 = "World";
    char *haystack2 = "1234567890";
    char *needle2 = "567";
    char *haystack3 = "abcdef";
    char *needle3 = "efg";
    char *haystack4 = "abcdef";
    char *needle4 = "";
    char *haystack5 = "abcdef";
    char *needle5 = "abcdef";
    char *haystack6 = "";
    char *needle6 = "a";
    char *haystack7 = "abcdef";
    char *needle7 = "a";
    char *haystack8 = "Hello, Hello!";
    char *needle8 = "Hello";

    // Test parameters: haystack, needle, and max length to search
    struct {
        char *haystack;
        char *needle;
        size_t len;
    } test_cases[] = {
        {haystack1, needle1, 13},  // Normal case, match within length
        {haystack2, needle2, 10},  // Match in the middle
        {haystack3, needle3, 6},   // No match
        {haystack4, needle4, 6},   // Empty needle
        {haystack5, needle5, 3},   // Partial match due to len
        {haystack6, needle6, 1},   // Empty haystack
        {haystack7, needle7, 1},   // Match at start
        {haystack8, needle8, 5},   // First occurrence within limit
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        char *haystack = test_cases[i].haystack;
        char *needle = test_cases[i].needle;
        size_t len = test_cases[i].len;

        // Call ft_strnstr and strnstr
        char *result_ft = ft_strnstr(haystack, needle, len);
        char *result_std = strnstr(haystack, needle, len);

        // Compare results
        if (result_ft != result_std) {
            printf("Mismatch: haystack='%s', needle='%s', len=%zu | ft_strnstr=%p, strnstr=%p\n", 
                   haystack, needle, len, result_ft, result_std);
        } else {
            printf("Match: haystack='%s', needle='%s', len=%zu | Result=%p\n", 
                   haystack, needle, len, result_ft);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}