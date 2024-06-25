#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int modulus(int a, int b);
int power(int a, int b);
int factorial(int a);

int main()
{
    // pointer = a "variable-like" reference that holds a memory address to another variable, array, etc.
    //           some tasks are performed more easily with pointers
    //           * = indirection operator (value at address)

    // malloc is used to allocate memory in the heap for variables that need to
    // be used dynamically. It returns a pointer to the allocated memory block,
    // or NULL if the allocation fails due to insufficient memory.

    // free is used to release the memory allocated by malloc, calloc, or realloc.
    // It deallocates the memory pointed to by the pointer, making it available
    // for further allocation.
    float *number1 = (float *)malloc(sizeof(float));
    float *number2 = (float *)malloc(sizeof(float));
    float *result = (float *)malloc(sizeof(float));
    char operation[10];

    if (number1 == NULL || number2 == NULL || result == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("What operation do you want to perform? (add, subtract, multiply, divide, modulus, power, factorial)\n");
    scanf("%s", operation);

    // Convert operation to uppercase
    for (int index = 0; operation[index]; index++)
    {
        operation[index] = toupper(operation[index]);
    }

    // Read input numbers based on operation
    if (strcmp(operation, "FACTORIAL") == 0)
    {
        printf("Enter the number: ");
        scanf("%f", number1);
        if (*number1 < 0 || (int)*number1 != *number1)
        {
            printf("Invalid input! Factorial is only defined for non-negative integers.\n");
            free(number1);
            free(number2);
            free(result);
            return 1;
        }
    }
    else
    {
        printf("Enter the first number: ");
        scanf("%f", number1);

        printf("Enter the second number: ");
        scanf("%f", number2);
    }

    // Perform operation using switch
    if (strcmp(operation, "ADD") == 0)
    {
        *result = add((int)*number1, (int)*number2);
    }
    else if (strcmp(operation, "SUBTRACT") == 0)
    {
        *result = subtract((int)*number1, (int)*number2);
    }
    else if (strcmp(operation, "MULTIPLY") == 0)
    {
        *result = multiply((int)*number1, (int)*number2);
    }
    else if (strcmp(operation, "DIVIDE") == 0)
    {
        if (*number2 != 0)
        {
            *result = divide((int)*number1, (int)*number2);
        }
        else
        {
            printf("Error! Division by zero.\n");
            free(number1);
            free(number2);
            free(result);
            return 1;
        }
    }
    else if (strcmp(operation, "MODULUS") == 0)
    {
        if (*number2 != 0)
        {
            *result = modulus((int)*number1, (int)*number2);
        }
        else
        {
            printf("Error! Division by zero.\n");
            free(number1);
            free(number2);
            free(result);
            return 1;
        }
    }
    else if (strcmp(operation, "POWER") == 0)
    {
        *result = power((int)*number1, (int)*number2);
    }
    else if (strcmp(operation, "FACTORIAL") == 0)
    {
        *result = factorial((int)*number1);
    }
    else
    {
        printf("Invalid operation\n");
        free(number1);
        free(number2);
        free(result);
        return 1;
    }

    printf("Result of %s operation: %.2f\n", operation, *result);

    // Free allocated memory
    free(number1);
    free(number2);
    free(result);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int modulus(int a, int b)
{
    return a % b;
}

int power(int a, int b)
{
    return pow(a, b);
}

int factorial(int a)
{
    int result = 1;
    for (int index = 1; index <= a; index++)
    {
        result *= index;
    }
    return result;
}
