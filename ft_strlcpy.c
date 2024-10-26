/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:48:16 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:45:01 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str)
{
    size_t i;
    if(!str)
    {
        return 0;
    }
    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

size_t ft_strlcpy (char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t src_len;
    
    src_len = ft_strlen(src);
    i = 0;
    
    if(dstsize > 0)
    {
        while(i < dstsize - 1 && src[i] != '\0')
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return src_len;
}
// Function to run test cases
void run_tests() {
    // Test source strings
    char *src1 = "Hello, World!";
    char *src2 = "1234567890";
    char *src3 = "";
    char *src4 = "This is a longer string.";
    char *src5 = "Short";

    // Test destination buffers
    char dst1[20];
    char dst2[10];
    char dst3[5];
    char dst4[50];
    char dst5[1];

    // Test parameters: destination buffer, source string, and buffer size
    struct {
        char *dst;
        const char *src;
        size_t dstsize;
    } test_cases[] = {
        {dst1, src1, sizeof(dst1)},  // Normal copy
        {dst2, src2, sizeof(dst2)},  // Partial copy
        {dst3, src2, sizeof(dst3)},  // Smaller buffer
        {dst4, src4, sizeof(dst4)},  // Larger buffer
        {dst5, src5, sizeof(dst5)},  // Buffer size of 1 (only null terminator)
        {dst1, src3, sizeof(dst1)},  // Empty source
        {dst1, src1, 0}             // Buffer size of 0
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        char dst_ft[50], dst_std[50];
        const char *src = test_cases[i].src;
        size_t dstsize = test_cases[i].dstsize;

        // Initialize destination buffers
        memset(dst_ft, 0, sizeof(dst_ft));
        memset(dst_std, 0, sizeof(dst_std));

        // Call ft_strlcpy and strlcpy
        size_t len_ft = ft_strlcpy(dst_ft, src, dstsize);
        size_t len_std = strlcpy(dst_std, src, dstsize);

        // Compare results
        if (len_ft != len_std || strcmp(dst_ft, dst_std) != 0) {
            printf("Mismatch: src='%s', dstsize=%zu | ft_strlcpy='%s' (%zu), strlcpy='%s' (%zu)\n", 
                   src, dstsize, dst_ft, len_ft, dst_std, len_std);
        } else {
            printf("Match: src='%s', dstsize=%zu | Result='%s' (%zu)\n", 
                   src, dstsize, dst_ft, len_ft);
        }
    }

}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}