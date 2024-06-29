#include <stdio.h>
#include <stdlib.h>

// Function declarations
void swap(int *x, int *y);
void printAge(int *pAge);
void dynamicArrayExample();
void arrayPointerExample();

int main() {
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
