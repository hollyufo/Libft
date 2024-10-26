/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:04:07 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:44:35 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *p = (unsigned char *)s;
    
    size_t i;

    i = 0;
    while (i < n)
    {
        p[i] = c;
        i++;
    }
    
    return s;
}

// Function to print buffer contents (for debugging)
void print_buffer(const char *label, unsigned char *buffer, size_t size) {
    printf("%s: ", label);
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");
}

// Function to run test cases
void run_tests() {
    // Test buffers
    unsigned char buffer1[50] = {0};
    unsigned char buffer2[50] = {0};
    unsigned char buffer3[50] = {0};

    // Test parameters: buffer, character to set, and length
    struct {
        unsigned char *buffer;
        int c;
        size_t n;
    } test_cases[] = {
        {buffer1, 'A', 10},  // Set 10 bytes to 'A'
        {buffer1, 'B', 20},  // Set 20 bytes to 'B'
        {buffer2, 'C', 0},   // Set 0 bytes
        {buffer2, 'D', 50},  // Set full buffer to 'D'
        {buffer3, 0xFF, 15}, // Set 15 bytes to 0xFF
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        unsigned char *buffer_ft = malloc(50);
        unsigned char *buffer_std = malloc(50);
        int c = test_cases[i].c;
        size_t n = test_cases[i].n;

        // Initialize buffers to zero for consistency
        memset(buffer_ft, 0, 50);
        memset(buffer_std, 0, 50);

        // Call ft_memset and memset
        ft_memset(buffer_ft, c, n);
        memset(buffer_std, c, n);

        // Compare results
        if (memcmp(buffer_ft, buffer_std, 50) != 0) {
            printf("Mismatch: Char='%c', Length=%zu\n", c, n);
            print_buffer("ft_memset", buffer_ft, 50);
            print_buffer("memset", buffer_std, 50);
        } else {
            printf("Match: Char='%c', Length=%zu\n", c, n);
        }

        // Free allocated memory
        free(buffer_ft);
        free(buffer_std);
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}