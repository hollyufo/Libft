/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:52:54 by imchaibi          #+#    #+#             */
/*   Updated: 2024/10/26 14:54:40 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int    ft_isspace(int c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

void run_tests() {
    // Array of test cases including normal, edge, and invalid cases
    const char *test_cases[] = {
        "123",         // Positive number
        "-456",        // Negative number
        "   789",      // Leading spaces
        "42abc",       // Numbers followed by characters
        "-00123",      // Negative with leading zeros
        "0",           // Zero
        "+12",         // Positive with plus sign
        "  +12",       // Leading spaces with plus sign
        "-2147483648", // INT_MIN
        "2147483647",  // INT_MAX
        "9999999999",  // Overflow
        "-9999999999", // Underflow
        "abc123",      // Non-numeric leading characters
        "   ",         // Only spaces
        ""             // Empty string
    };
    
    // Number of test cases
    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    // Test each case
    for (size_t i = 0; i < num_cases; i++) {
        const char *test_str = test_cases[i];
        int result_ft_atoi = ft_atoi(test_str);
        int result_atoi = atoi(test_str);
        
        // Compare outputs
        if (result_ft_atoi != result_atoi) {
            printf("Mismatch: Input='%s' | ft_atoi=%d, atoi=%d\n", test_str, result_ft_atoi, result_atoi);
        } else {
            printf("Match: Input='%s' | Result=%d\n", test_str, result_ft_atoi);
        }
    }
}

// Main function to run the test suite
int main() {
    run_tests();
    return 0;
}