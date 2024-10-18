#include <iostream>
#include <cmath>
#include <string>

bool isKaprekar(int n, int base) {
    // Calculate the square of the number
    long long square = static_cast<long long>(n) * n;

    // Convert number and its square to the specified base
    std::string nBase = "";
    std::string squareBase = "";

    // Convert n to base
    int tempN = n;
    while (tempN > 0) {
        nBase = std::to_string(tempN % base) + nBase;
        tempN /= base;
    }

    // Convert square to base
    long long tempSquare = square;
    while (tempSquare > 0) {
        squareBase = std::to_string(tempSquare % base) + squareBase;
        tempSquare /= base;
    }

    // Length of n in base
    int d = nBase.length();
    int squareLength = squareBase.length();

    // Split the square representation into two parts
    std::string rightPart = squareBase.substr(squareLength - d);
    std::string leftPart = squareBase.substr(0, squareLength - d);

    // Convert parts back to base 10
    int rightValue = std::stoi(rightPart);
    int leftValue = leftPart.empty() ? 0 : std::stoi(leftPart);

    // Check if the sum of left and right parts equals n
    return (leftValue + rightValue == n);
}

int main() {
    int number, base;

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << "Enter a base: ";
    std::cin >> base;

    if (isKaprekar(number, base)) {
        std::cout << number << " is a Kaprekar number in base " << base << ".\n";
    } else {
        std::cout << number << " is not a Kaprekar number in base " << base << ".\n";
    }

    return 0;
}
