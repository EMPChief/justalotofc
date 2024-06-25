#include <stdio.h>
#include <stdlib.h>

// Function declarations
void swap(int *x, int *y);
void printAge(int *pAge);
void dynamicArrayExample();
void arrayPointerExample();

int main() {
    // pointer = a "variable-like" reference that holds a memory address to another variable, array, etc.
    //           some tasks are performed more easily with pointers
    //           * = indirection operator (value at address)
    
    // Using pointers to swap two variables
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    // Using pointers to print an age
    int age = 21;
    int *pAge = &age;
    printAge(pAge);

    // Dynamic Memory Allocation
    dynamicArrayExample();

    // Using pointers to access array elements
    arrayPointerExample();

    return 0;
}

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to print age using a pointer
void printAge(int *pAge) {
    printf("You are %d years old\n", *pAge); // Dereference
}

// Function to demonstrate dynamic memory allocation
void dynamicArrayExample() {
    int n;
    printf("\nEnter the number of elements for dynamic array: ");
    scanf("%d", &n);

    // Allocating memory dynamically for an array of n integers
    int *dynArr = (int *)malloc(n * sizeof(int));
    if (dynArr == NULL) {
        printf("Memory allocation failed\n");
        return;
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
}

// Function to demonstrate using pointers to access array elements
void arrayPointerExample() {
    int arr2[3] = {10, 20, 30};
    int *ptr2 = arr2;

    // Printing array elements and their addresses using pointers
    printf("\nUsing pointers to access array elements:\n");
    for (int i = 0; i < 3; i++) {
        printf("arr2[%d] = %d, Address = %p\n", i, *(ptr2 + i), (void *)(ptr2 + i));
    }
}
