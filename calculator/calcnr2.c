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
void release_memory(float *ptr1, float *ptr2, float *ptr3);



int main()
{
    // A pointer is a variable  stores the memory address of another variable, 
    // array, or function. Pointers athatre useful for dynamic memory management, 
    // array manipulation, and function argument passing.
    // The * operator is called the indirection or dereference operator, 
    // and it is used to access the value stored at the memory address a pointer refers to.

    // malloc (memory allocation) is a function used to allocate a specified amount 
    // of memory in the heap. It returns a pointer to the beginning of the allocated 
    // memory block, or NULL if the allocation fails due to insufficient memory.
    // Syntax: void* malloc(size_t size);

    // calloc (contiguous allocation) is a function used to allocate memory for an array 
    // of elements, initializing all bytes to zero. It returns a pointer to the allocated 
    // memory block, or NULL if the allocation fails.
    // Syntax: void* calloc(size_t num, size_t size);

    // realloc (reallocation) is a function used to resize a previously allocated memory 
    // block. It returns a pointer to the newly allocated memory, which may be at a 
    // different location, or NULL if the reallocation fails.
    // Syntax: void* realloc(void* ptr, size_t new_size);

    // aligned_alloc is a function used to allocate memory aligned to a specified boundary.
    // It returns a pointer to the allocated memory block, or NULL if the allocation fails.
    // Syntax: void* aligned_alloc(size_t alignment, size_t size);

    // free is a function used to deallocate memory that was previously allocated 
    // using malloc, calloc, or realloc. This releases the memory back to the heap 
    // for future use. After calling free, the pointer becomes invalid and should 
    // not be used until it is reallocated.
    // Syntax: void free(void* ptr);

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
            release_memory(number1, number2, result);

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
            release_memory(number1, number2, result);
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
            release_memory(number1, number2, result);
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
        release_memory(number1, number2, result);
        return 1;
    }

    printf("Result of %s operation: %.2f\n", operation, *result);

    // Free allocated memory
    release_memory(number1, number2, result);

    return 0;
}
void release_memory(float *ptr1, float *ptr2, float *ptr3)
{
    free(ptr1);
    free(ptr2);
    free(ptr3);
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
