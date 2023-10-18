/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:46:18 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/16 16:46:21 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>

// Define a fixed-point format with a range of 0 to 10 seconds and 1 ms resolution.
using FixedPointTime = int16_t;  // 16 bits for simplicity.

int main() {
    FixedPointTime timeValue = 5000;  // Represents 5.000 seconds (5000 ms).

    // Attempt to represent a time interval longer than the defined range.
    FixedPointTime longerTimeValue = 15000;  // Represents 15.000 seconds (15000 ms).

    std::cout << "Time value: " << timeValue << " milliseconds (" << static_cast<double>(timeValue) / 1000 << " seconds)" << std::endl;
    std::cout << "Longer time value: " << longerTimeValue << " milliseconds (" << static_cast<double>(longerTimeValue) / 1000 << " seconds)" << std::endl;

    return 0;
}
