/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:44:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 14:57:58 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void ft_bzero(void *s, size_t n)
{
        unsigned char *p = (unsigned char *)s;
    
    size_t i;

    i = 0;
    while (i < n)
    {
        p[i] = 0;
        i++;
    }
}


// Helper function to print buffer contents (for debugging)
void print_buffer(const char *label, unsigned char *buffer, size_t size) {
    printf("%s: ", label);
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");
}

// Function to run test cases
void run_tests() {
    // Array of test cases for buffer sizes
    size_t test_sizes[] = {
        0,       // Zero length
        1,       // Smallest possible buffer
        5,       // Small buffer
        10,      // Medium buffer
        100,     // Large buffer
        1024     // Very large buffer
    };
    
    // Number of test cases
    size_t num_cases = sizeof(test_sizes) / sizeof(test_sizes[0]);
    
    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        size_t buffer_size = test_sizes[i];
        
        // Allocate two buffers of the same size
        unsigned char buffer1[buffer_size];
        unsigned char buffer2[buffer_size];
        
        // Initialize both buffers with non-zero values (0xAB)
        memset(buffer1, 0xAB, buffer_size);
        memset(buffer2, 0xAB, buffer_size);
        
        // Apply ft_bzero and bzero to respective buffers
        ft_bzero(buffer1, buffer_size);
        bzero(buffer2, buffer_size);
        
        // Compare the results
        if (memcmp(buffer1, buffer2, buffer_size) != 0) {
            printf("Mismatch for size %zu\n", buffer_size);
            print_buffer("ft_bzero", buffer1, buffer_size);
            print_buffer("bzero", buffer2, buffer_size);
        } else {
            printf("Match for size %zu\n", buffer_size);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}