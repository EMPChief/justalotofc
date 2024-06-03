#include <stdio.h>

// Function prototype for the square function
// This declares the function so the compiler knows about it before main
double square(double x);

int main()
{
    // Declare a variable to hold the result of the square function
    double x;

    // Call the square function with 3.14 as the argument and store the result in x
    x = square(3.14);

    // Print the result using printf
    // %lf is the format specifier for printing a double
    printf("%lf\n", x);

    // Return 0 to indicate successful execution of the program
    return 0;
}

// Function definition for the square function
// This function takes a double as an input and returns its square
double square(double x)
{
    // Declare a variable to hold the result
    double result;

    // Calculate the square of the input
    result = x * x;

    // Return the result
    return result;
}
