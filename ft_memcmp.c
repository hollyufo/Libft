/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:47:16 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:44:14 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str1;
    unsigned char *str2;
    size_t i;

    i = 0;
    str1 = (unsigned char *) s1;
    str2 = (unsigned char *) s2;

    while(i < n)
    {
        if(str1[i] != str2[i])
        {
            return (str1[i] - str2[i]);
        }
        i++;
    }
    return (0);
}

// Function to run test cases
void run_tests() {
    // Test cases: different buffer pairs and lengths
    unsigned char buffer1[] = "Hello, World!";
    unsigned char buffer2[] = "Hello, World!";
    unsigned char buffer3[] = "HELLO, WORLD!";
    unsigned char buffer4[] = "Hello, Universe!";
    unsigned char buffer5[] = "";
    unsigned char buffer6[] = "1234567890";
    
    // Test parameters: pairs of buffers and length to compare
    struct {
        unsigned char *buffer1;
        unsigned char *buffer2;
        size_t n;
    } test_cases[] = {
        {buffer1, buffer2, 13},  // Identical buffers
        {buffer1, buffer3, 13},  // Different buffers, same length
        {buffer1, buffer4, 13},  // Partial match
        {buffer1, buffer4, 5},   // Partial length match
        {buffer5, buffer5, 0},   // Empty buffers
        {buffer6, buffer6, 10},  // Identical numeric buffers
        {buffer6, buffer4, 0},   // Zero length comparison
    };
    
    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        unsigned char *buf1 = test_cases[i].buffer1;
        unsigned char *buf2 = test_cases[i].buffer2;
        size_t n = test_cases[i].n;
        
        // Call ft_memcmp and memcmp
        int result_ft = ft_memcmp(buf1, buf2, n);
        int result_std = memcmp(buf1, buf2, n);
        
        // Compare results
        if (result_ft != result_std) {
            printf("Mismatch: Buffer1='%s', Buffer2='%s', Length=%zu | ft_memcmp=%d, memcmp=%d\n", 
                   buf1, buf2, n, result_ft, result_std);
        } else {
            printf("Match: Buffer1='%s', Buffer2='%s', Length=%zu | Result=%d\n", 
                   buf1, buf2, n, result_ft);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}