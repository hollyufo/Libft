/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:45:05 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:44:42 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strchr(const char *s, int c)
{
    int i;
    char char_to_find;

    char_to_find = (char) c;
    i = 0;
    
    while(s[i])
    {
        if(s[i] == char_to_find)
        {
            return ((char *) &s[i]);
        }
        i++;
    }
    if (s[i] == char_to_find)
    {
        return ((char *) &s[i]);
    }
    return (NULL);
}

// Function to run test cases
void run_tests() {
    // Test strings
    char str1[] = "Hello, World!";
    char str2[] = "This is a test.";
    char str3[] = "abcdefg";
    char str4[] = "1234567890";
    char str5[] = "";
    
    // Test parameters: string and character to find
    struct {
        char *str;
        int c;
    } test_cases[] = {
        {str1, 'W'},  // Character present in the middle
        {str1, 'H'},  // Character at the start
        {str1, '!'},  // Character at the end
        {str1, 'z'},  // Character not present
        {str2, ' '},  // Space character
        {str2, '.'},  // Period at the end
        {str3, 'a'},  // Character at the start
        {str3, 'g'},  // Character at the end
        {str4, '5'},  // Number in the middle
        {str4, '0'},  // Number at the end
        {str5, 'a'},  // Empty string
        {str1, '\0'}, // Null terminator
    };
    
    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        char *str = test_cases[i].str;
        int c = test_cases[i].c;
        
        // Call ft_strchr and strchr
        char *result_ft = ft_strchr(str, c);
        char *result_std = strchr(str, c);
        
        // Compare results
        if (result_ft != result_std) {
            printf("Mismatch: String='%s', Char='%c' | ft_strchr=%p, strchr=%p\n", 
                   str, c, result_ft, result_std);
        } else {
            printf("Match: String='%s', Char='%c' | Result=%p\n", str, c, result_ft);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}