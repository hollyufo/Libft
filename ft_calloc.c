/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:17:09 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 15:00:24 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *ft_calloc(size_t count, size_t size)
{
    unsigned char *temp_str;
    size_t i;
    
    i = 0;
    temp_str = malloc(count * size);
    
    if(!temp_str)
    {
        return (NULL);
    }
    while (i < count * size)
    {
        temp_str[i] = 0;
        i++;
    }
    
    return (temp_str);
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
    // Array of test cases (count, size)
    size_t test_cases[][2] = {
        {0, 0},         // Both count and size are zero
        {1, 0},         // Count is one, size is zero
        {0, 1},         // Count is zero, size is one
        {1, 1},         // Minimum allocation
        {10, 1},        // Multiple allocations of size 1
        {1, 10},        // Single allocation of size 10
        {5, 20},        // Moderate allocation
        {100, 10},      // Large number of small allocations
        {1024, 1024}    // Large allocation (1 MB)
    };

    // Number of test cases
    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        size_t count = test_cases[i][0];
        size_t size = test_cases[i][1];
        size_t total_size = count * size;
        
        // Allocate memory using ft_calloc and calloc
        unsigned char *buffer1 = ft_calloc(count, size);
        unsigned char *buffer2 = calloc(count, size);
        
        // Check if both allocations are successful
        if (!buffer1 || !buffer2) {
            printf("Allocation failed for count=%zu, size=%zu\n", count, size);
            if (buffer1) free(buffer1);
            if (buffer2) free(buffer2);
            continue;
        }
        
        // Compare the contents
        if (memcmp(buffer1, buffer2, total_size) != 0) {
            printf("Mismatch for count=%zu, size=%zu\n", count, size);
            print_buffer("ft_calloc", buffer1, total_size);
            print_buffer("calloc", buffer2, total_size);
        } else {
            printf("Match for count=%zu, size=%zu\n", count, size);
        }

        // Free allocated memory
        free(buffer1);
        free(buffer2);
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}