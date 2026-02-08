#include <stdio.h>

// Recursive function to calculate power
long long power(int a, int b) {
    // Base case: any number to the power of 0 is 1
    if (b == 0) {
        return 1;
    }
    // Recursive step
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    
    // Taking input
    if (scanf("%d %d", &a, &b) == 2) {
        // Handle case for non-negative exponents
        if (b < 0) {
            printf("Exponent should be non-negative.\n");
        } else {
            printf("%lld\n", power(a, b));
        }
    }
    
    return 0;
}