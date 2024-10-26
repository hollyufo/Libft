/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:05:24 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:44:07 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *str;
    unsigned char c_to_find;
    size_t i;

    str = (unsigned char *) s;
    c_to_find = (unsigned char) c;
    i = 0;

    while (i < n)
    {
        if(str[i] == c_to_find)
        {
            return ((void *) &str[i]);
        }
        i++;
    }
    return (NULL);
}

void run_tests() {
    // Test cases: different buffers and lengths
    unsigned char buffer1[] = "Hello, World!";
    unsigned char buffer2[] = "This is a test buffer.";
    unsigned char buffer3[] = "1234567890";
    unsigned char buffer4[] = "";
    
    // Test parameters: character to find and length to search
    struct {
        unsigned char *buffer;
        int c;
        size_t n;
    } test_cases[] = {
        {buffer1, 'W', 13},    // Find 'W' in buffer1
        {buffer1, 'z', 13},    // 'z' not in buffer1
        {buffer2, 't', 20},    // Find 't' in buffer2
        {buffer2, 'T', 20},    // 'T' not in buffer2
        {buffer3, '5', 10},    // Find '5' in buffer3
        {buffer3, '0', 10},    // Find '0' in buffer3
        {buffer4, 'a', 0},     // Empty buffer
    };
    
    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        unsigned char *buffer = test_cases[i].buffer;
        int c = test_cases[i].c;
        size_t n = test_cases[i].n;
        
        // Call ft_memchr and memchr
        void *result_ft = ft_memchr(buffer, c, n);
        void *result_std = memchr(buffer, c, n);
        
        // Compare results
        if (result_ft != result_std) {
            printf("Mismatch: Buffer='%s', Char='%c', Length=%zu | ft_memchr=%p, memchr=%p\n", 
                   buffer, c, n, result_ft, result_std);
        } else {
            printf("Match: Buffer='%s', Char='%c', Length=%zu | Result=%p\n", 
                   buffer, c, n, result_ft);
        }
    }

}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}