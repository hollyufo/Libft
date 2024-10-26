/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:19:20 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:44:21 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *temp_dst;
    unsigned char *temp_src;
    
    if (!dst && !src) {
        return dst;
    }
    
    temp_dst = (unsigned char *)dst;
    temp_src = (unsigned char *)src;
    
	while (n > 0)
	{
		*(temp_dst++) = *(temp_src++);
        n--;
	}
	return temp_dst;
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
    // Test cases: different source buffers and lengths
    unsigned char src1[] = "Hello, World!";
    unsigned char src2[] = "1234567890";
    unsigned char src3[] = "";
    unsigned char src4[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Test parameters: source buffer, length to copy
    struct {
        unsigned char *src;
        size_t n;
    } test_cases[] = {
        {src1, 13},   // Full copy of src1
        {src1, 5},    // Partial copy of src1
        {src2, 10},   // Full copy of src2
        {src2, 5},    // Partial copy of src2
        {src3, 0},    // Empty source
        {src4, 26},   // Full copy of src4
        {src4, 10},   // Partial copy of src4
    };
    
    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        unsigned char *src = test_cases[i].src;
        size_t n = test_cases[i].n;
        
        // Create destination buffers for ft_memcpy and memcpy
        unsigned char dest_ft[100] = {0};  // Initial buffer set to 0
        unsigned char dest_std[100] = {0}; // Initial buffer set to 0
        
        // Call ft_memcpy and memcpy
        ft_memcpy(dest_ft, src, n);
        memcpy(dest_std, src, n);
        
        // Compare results
        if (memcmp(dest_ft, dest_std, n) != 0) {
            printf("Mismatch: Src='%s', Length=%zu\n", src, n);
            print_buffer("ft_memcpy", dest_ft, n);
            print_buffer("memcpy", dest_std, n);
        } else {
            printf("Match: Src='%s', Length=%zu\n", src, n);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}