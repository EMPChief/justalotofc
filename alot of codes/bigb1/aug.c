#include <stdio.h>
 
int main(){
  
    // Augmented assignment operators are used to replace a statement where an operator
    // takes a variable as one of its arguments and then assigns the result back to the same variable.
    // For example: x = x + 1 can be replaced with x += 1.

    int x = 10;

    // Addition: x = x + 2
    x += 2;
    printf("After addition: %d\n", x);

    // Subtraction: x = x - 3
    x -= 3;
    printf("After subtraction: %d\n", x);

    // Multiplication: x = x * 4
    x *= 4;
    printf("After multiplication: %d\n", x);

    // Division: x = x / 5
    x /= 5;
    printf("After division: %d\n", x);

    // Modulo: x = x % 2
    x %= 2;
    printf("After modulo: %d\n", x);
    
    return 0;
}
