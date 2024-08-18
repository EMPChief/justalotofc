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
    int *number1 = (int *)malloc(sizeof(int));
    int *number2 = (int *)malloc(sizeof(int));
    int *result = (int *)malloc(sizeof(int));
    char operation[10];

    if (number1 == NULL || number2 == NULL || result == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("What operation do you want to perform? (add, subtract, multiply, divide, modulus, power, factorial)\n");
    if (scanf("%s", operation) != 1) {
        printf("Failed to read the operation!\n");
        free(number1);
        free(number2);
        free(result);
        return 1;
    }

    // Convert operation to uppercase
    for (int index = 0; operation[index]; index++)
    {
        operation[index] = toupper(operation[index]);
    }

    // Read input numbers based on operation
    if (strcmp(operation, "FACTORIAL") == 0)
    {
        printf("Enter the number: ");
        if (scanf("%d", number1) != 1) {
            printf("Failed to read the number!\n");
            free(number1);
            free(number2);
            free(result);
            return 1;
        }
        if (*number1 < 0)
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
        if (scanf("%d", number1) != 1) {
            printf("Failed to read the first number!\n");
            free(number1);
            free(number2);
            free(result);
            return 1;
        }

        printf("Enter the second number: ");
        if (scanf("%d", number2) != 1) {
            printf("Failed to read the second number!\n");
            free(number1);
            free(number2);
            free(result);
            return 1;
        }
    }

    // Perform operation using if-else
    if (strcmp(operation, "ADD") == 0)
    {
        *result = add(*number1, *number2);
    }
    else if (strcmp(operation, "SUBTRACT") == 0)
    {
        *result = subtract(*number1, *number2);
    }
    else if (strcmp(operation, "MULTIPLY") == 0)
    {
        *result = multiply(*number1, *number2);
    }
    else if (strcmp(operation, "DIVIDE") == 0)
    {
        if (*number2 != 0)
        {
            *result = divide(*number1, *number2);
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
            *result = modulus(*number1, *number2);
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
        *result = power(*number1, *number2);
    }
    else if (strcmp(operation, "FACTORIAL") == 0)
    {
        *result = factorial(*number1);
    }
    else
    {
        printf("Invalid operation\n");
        free(number1);
        free(number2);
        free(result);
        return 1;
    }

    printf("Result of %s operation: %d\n", operation, *result);

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
    return (int)pow(a, b);
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
