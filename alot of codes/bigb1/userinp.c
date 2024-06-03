#include <stdio.h>
#include <string.h>

int main()
{
    // declare and initialize variables
    char name[100]; // Declares a character array to store the user's name with a maximum length of 100 characters
    int age;        // Declares an integer variable to store the user's age

    // Prompts the user to enter their name
    printf("What is your name? ");
    // Gets user input and stores it in the 'name' variable, with a maximum of 100 characters, and removes the newline character at the end of the input string if it exists using the fgets function
    fgets(name, 100, stdin);
    // Removes the newline character at the end of the input string if it exists using the strcspn function
    name[strcspn(name, "\n")] = 0;

    // Prompts the user to enter their age
    printf("\nHow old are you? ");
    // Gets user input and stores it in the 'age' variable as an integer value, with no limit, using the scanf function
    scanf("%d", &age);

    // Prints a message to the user with their name and age
    printf("\nHello, %s! You are %d years old.\n", name, age);
}
