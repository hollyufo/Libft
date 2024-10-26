/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:13:22 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 17:44:52 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize) {
    size_t dst_len = 0;
    size_t src_len = ft_strlen(src);
    size_t i = 0;

    while (dst[dst_len] != '\0' && dst_len < dstsize) {
        dst_len++;
    }

    if (dst_len >= dstsize) {
        return dstsize + src_len;
    }

    size_t space_left = dstsize - dst_len - 1;

    while (i < space_left && src[i] != '\0') {
        dst[dst_len + i] = src[i];
        i++;
    }

    dst[dst_len + i] = '\0';

    return dst_len + src_len;
}
// Function to run test cases
void run_tests() {
    // Test buffers
    char dst1[20] = "Hello, ";
    char dst2[20] = "Hello, ";
    char dst3[20] = "";
    char dst4[5] = "Hi";
    char dst5[20] = "Start";

    // Test source strings
    char *src1 = "World!";
    char *src2 = "Test";
    char *src3 = "";
    char *src4 = "Longer than buffer";

    // Test parameters: destination buffer, source string, and buffer size
    struct {
        char *dst;
        const char *src;
        size_t dstsize;
    } test_cases[] = {
        {dst1, src1, 20},  // Normal case
        {dst2, src2, 10},  // Exact fit
        {dst3, src1, 15},  // Empty destination
        {dst4, src1, 5},   // Small destination buffer
        {dst5, src3, 20},  // Empty source
        {dst5, src4, 15},  // Source longer than remaining space
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate through each test case
    for (size_t i = 0; i < num_cases; i++) {
        char dst_ft[20], dst_std[20];
        const char *src = test_cases[i].src;
        size_t dstsize = test_cases[i].dstsize;

        // Copy the destination buffer for consistency
        strncpy(dst_ft, test_cases[i].dst, sizeof(dst_ft));
        strncpy(dst_std, test_cases[i].dst, sizeof(dst_std));

        // Call ft_strlcat and strlcat
        size_t len_ft = ft_strlcat(dst_ft, src, dstsize);
        size_t len_std = strlcat(dst_std, src, dstsize);

        // Compare results
        if (len_ft != len_std || strcmp(dst_ft, dst_std) != 0) {
            printf("Mismatch: dst='%s', src='%s', dstsize=%zu | ft_strlcat='%s' (%zu), strlcat='%s' (%zu)\n", 
                   test_cases[i].dst, src, dstsize, dst_ft, len_ft, dst_std, len_std);
        } else {
            printf("Match: dst='%s', src='%s', dstsize=%zu | Result='%s' (%zu)\n", 
                   test_cases[i].dst, src, dstsize, dst_ft, len_ft);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}