#include <iostream>
#include <cmath>
using namespace std;

// Function to count the number of digits in a number
int countDigits(long long n) {
    return (int)log10(n) + 1;
}

// Function to multiply two numbers using Karatsuba algorithm
long long karatsubaMultiply(long long x, long long y) {
    // Base case
    if (x < 10 || y < 10) {
        return x * y;
    }

    // Calculate the number of digits in x and y
    int n = max(countDigits(x), countDigits(y));

    // Calculate the number of digits in half the number of digits in x and y
    int half = n / 2;

    // Calculate the divisor and multipliers
    long long divisor = (long long)pow(10, half);
    long long x1 = x / divisor;
    long long x0 = x % divisor;
    long long y1 = y / divisor;
    long long y0 = y % divisor;

    // Recursive steps
    long long z0 = karatsubaMultiply(x0, y0);
    long long z2 = karatsubaMultiply(x1, y1);
    long long z1 = karatsubaMultiply((x0 + x1), (y0 + y1)) - z0 - z2;

    // Calculate the final result using the formula: z2 * 10^(2*half) + z1 * 10^half + z0
    long long result = z2 * (long long)pow(10, 2 * half) + z1 * (long long)pow(10, half) + z0;

    return result;
}

int main() {
    long long x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    long long result = karatsubaMultiply(x, y);
    cout << "Product: " << result << endl;

    return 0;
}
