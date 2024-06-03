#include <stdio.h>

int main() {
    // Arithmetic operations
    // Addition
    float a = 10.5;
    float b = 5.2;
    printf("Addition: %.2f + %.2f = %.2f\n", a, b, a + b);

    // Subtraction
    printf("Subtraction: %.2f - %.2f = %.2f\n", a, b, a - b);

    // Multiplication
    printf("Multiplication: %.2f * %.2f = %.2f\n", a, b, a * b);

    // Division
    printf("Division: %.2f / %.2f = %.2f\n", a, b, a / b);
   
    // Modulo, increment, decrement are demonstrated with integer variables
    int intA = 10;
    int intB = 5;
    
    // Modulo
    // Modulo operation returns the remainder of the division
    printf("Modulo: %d %% %d = %d\n", intA, intB, intA % intB);
    
    // Increment
    // Increment operator increases the value of a variable by 1
    printf("Increment: %d++ = %d\n", intA, intA++);
    
    // Decrement
    // Decrement operator decreases the value of a variable by 1
    printf("Decrement: %d-- = %d\n", intA, intA--);

    // Casting
    // Casting is the conversion of one data type to another
    // Example of casting into float
    printf("Casting: %d = %f\n", intA, (float)intA / (float)intB);
    
    return 0;
}
