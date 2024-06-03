#include <stdio.h>

int main() {
    // Declare and initialize variables
    int x;
    // Set the value of x to 5
    x = 5;
    // Declare and initialize another variable
    int y;
    // Set the value of y to 10
    y = 10;
    // declare and initialize more variables
    int a, b;
    // set the values of a and b to 5 and 10, respectively
    a = 5; b = 10;
    // Print the values of x, y, a, and b
    printf("Values of x, y, a, and b: %d %d %d %d\n", x, y, a, b);
    // Declare and initialize variables for personal information
    // Array data type
    char name[] = "John";
    // Integer data type
    int age = 25;
    // Floating-point data type
    float gpa = 3.25;
    // Character data type
    char grade = 'A';

    // Print personal information
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Grade: %c\n", grade);
    /*
    %s - String
    %d - Integer
    %.2f - Floating-point
    %c - Character
    */

    return 0;
}
