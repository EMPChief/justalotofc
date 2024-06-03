#include <stdio.h>

int main() {
    // Constant - Fixed value that cannot be altred or changed at runtime
    // This is not a const variable and it can be changed at runtime
    float pi = 3.14159;
    // This is a const variable and it cannot be changed at runtime
    const float PITH = 3.14159;

    // Print the values of pi and PITH
    printf("pi = %f\n", pi);
    printf("const pi = %f\n", PITH);

    return 0;
}