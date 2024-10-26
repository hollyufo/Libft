/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:05:55 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:44:29 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *temp_dst;
    unsigned char *temp_src;
    
    if (!dst && !src)
    {
        return dst;
    }

    temp_dst = (unsigned char *)dst;
    temp_src = (unsigned char *)src;

    if (temp_src < temp_dst && (temp_src + len) > temp_dst)
    {
        // copy backwards as the mem overlaps 
        temp_dst += len - 1;
        temp_src += len - 1;
        while (len--) {
            *temp_dst-- = *temp_src--;
        }
    }
    else 
    {
        // No overlap copy normally
        while (len--)
        {
            *temp_dst++ = *temp_src++;
        }
    }
    
    return dst;
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
    unsigned char buffer1[] = "Hello, World!";
    unsigned char buffer2[] = "1234567890";
    unsigned char buffer3[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned char buffer4[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Test parameters: source, destination, and length to move
    struct {
        unsigned char *src;
        unsigned char *dest;
        size_t n;
    } test_cases[] = {
        {buffer1, buffer1 + 6, 6},  // Overlapping: forward
        {buffer1 + 6, buffer1, 6},  // Overlapping: backward
        {buffer2, buffer2 + 5, 5},  // Overlapping: forward
        {buffer2 + 5, buffer2, 5},  // Overlapping: backward
        {buffer3, buffer3 + 2, 20}, // Large forward overlap
        {buffer4 + 2, buffer4, 20}, // Large backward overlap
    };
    
    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        unsigned char *src = test_cases[i].src;
        unsigned char *dest_ft = malloc(50);
        unsigned char *dest_std = malloc(50);
        size_t n = test_cases[i].n;

        // Copy source buffer to destination buffers for consistency
        memcpy(dest_ft, src, 50);
        memcpy(dest_std, src, 50);
        
        // Call ft_memmove and memmove
        ft_memmove(dest_ft, src, n);
        memmove(dest_std, src, n);
        
        // Compare results
        if (memcmp(dest_ft, dest_std, n) != 0) {
            printf("Mismatch: Src='%s', Length=%zu\n", src, n);
            print_buffer("ft_memmove", dest_ft, n);
            print_buffer("memmove", dest_std, n);
        } else {
            printf("Match: Src='%s', Length=%zu\n", src, n);
        }

        // Free allocated memory
        free(dest_ft);
        free(dest_std);
    }

}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}
