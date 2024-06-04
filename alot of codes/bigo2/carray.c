#include <stdio.h>

int main() {
    // Array = a data strucutre that can hold a fixed number of values of the same type
    int array[5] = {1, 2, 3, 4, 5};
    printf("Array (full array): %d %d %d %d %d\n", array[0], array[1], array[2], array[3], array[4]);
    // Array with a loop 
    for (int i = 0; i < 5; i++) {
        printf("Array (loop): %d\n", array[i]);
    }
    // Array with a for loop and a break statement
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            break;
        }
        printf("Array (break): %d\n", array[i]);
    }
    // Array with a for loop and a continue statement
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            continue;
        }
        printf("Array (continue): %d\n", array[i]);
    }
    // Array with a while loop
    int i = 0;
    while (i < 5) {
        printf("Array (while): %d\n", array[i]);
        i++;
    }
    double prices[5] = {1.99, 2.99, 3.99, 4.99, 5.99};
    printf("Array (full array): %f %f %f %f %f\n", prices[0], prices[1], prices[2], prices[3], prices[4]);
    return 0;
}
