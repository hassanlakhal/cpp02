/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:18:45 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/16 21:38:11 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <iostream>
#include <cstdint>
#include <cmath>

class FixedPoint {
public:
    FixedPoint(int integerPart, int fractionalPart, int fractionalBits) {
        int maxIntegerValue = (1 << (31 - fractionalBits)) - 1;
        int minIntegerValue = -maxIntegerValue;

        if (integerPart < minIntegerValue || integerPart > maxIntegerValue) {
            std::cerr << "Integer part out of range." << std::endl;
            exit(1);
        }

        if (fractionalPart < 0 || fractionalPart >= (1 << fractionalBits)) {
            std::cerr << "Fractional part out of range." << std::endl;
            exit(1);
        }

        value_ = (integerPart << fractionalBits) + fractionalPart;
    }

    double toDouble(int fractionalBits) const {
        return static_cast<double>(value_) / std::pow(2, fractionalBits);
    }

private:
    int value_;
};

int main() {
    // Create a FixedPoint type with 2 fractional bits (range: -2 to 2).
    FixedPoint fixedValue(1, 0, 2);
    std::cout << "FixedPoint Value: " << fixedValue.toDouble(2) << std::endl; // Outputs 2.5
    FixedPoint fixedValue1(1, 500, 2);
    return 0;
}


