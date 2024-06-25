#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *x, int *y);

int main() {
    // memory = an array of bytes within RAM (street)
    // memory block = a single unit (byte) within memory (house), used to hold some value (person)
    // memory address = the address of where a memory block is located (house address)


    // Using sizeof with Different Data Types
    char a;
    int b;
    double c;
    char d[10];

    // Printing sizes of different data types
    printf("Size of char: %zu bytes\n", sizeof(a));
    printf("Size of int: %zu bytes\n", sizeof(b));
    printf("Size of double: %zu bytes\n", sizeof(c));
    printf("Size of array of 10 chars: %zu bytes\n", sizeof(d));

    // Pointer Arithmetic
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    // Demonstrating pointer arithmetic
    printf("\nArray base address: %p\n", (void *)arr);
    printf("Pointer address: %p\n", (void *)ptr);
    printf("Value at pointer: %d\n", *ptr);

    // Incrementing pointer to point to the next array element
    ptr++;
    printf("Pointer address after increment: %p\n", (void *)ptr);
    printf("Value at new pointer location: %d\n", *ptr);

    // Dynamic Memory Allocation
    int n;
    printf("\nEnter the number of elements for dynamic array: ");
    scanf("%d", &n);

    // Allocating memory dynamically for an array of n integers
    int *dynArr = (int *)malloc(n * sizeof(int));
    if (dynArr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initializing and printing the dynamically allocated array
    for (int i = 0; i < n; i++) {
        dynArr[i] = i + 1;
    }

    printf("Dynamically allocated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynArr[i]);
    }
    printf("\n");

    // Freeing the allocated memory
    free(dynArr);

    // Passing Pointers to Functions
    int x = 5, y = 10;

    printf("\nBefore swap: x = %d, y = %d\n", x, y);
    // Calling the swap function with pointers
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    // Using Pointers to Access Array Elements
    int arr2[3] = {10, 20, 30};
    int *ptr2 = arr2;

    // Printing array elements and their addresses using pointers
    printf("\nUsing pointers to access array elements:\n");
    for (int i = 0; i < 3; i++) {
        printf("arr2[%d] = %d, Address = %p\n", i, *(ptr2 + i), (void *)(ptr2 + i));
    }

    return 0;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}