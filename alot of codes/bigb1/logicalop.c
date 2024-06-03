#include <stdio.h>
#include <stdbool.h>

int main() {
    // Logical operators

    // Declare and initialize variables
    bool a = true;
    bool b = false;

    // Using the logical OR operator (||)
    // c is set to a OR b (1 if either a or b is true, 0 if both are false)
    bool c = a || b;

    // Using the logical AND operator (&&)
    // d is set to a AND b (1 if both a and b are true, 0 if either or both are false)
    bool d = a && b;

    // Printing the results
    printf("a || b = %d\n", c); // Output: 1 (true)
    printf("a && b = %d\n", d); // Output: 0 (false)

    // Using logical operators with conditions
    float temp = 15.2;
    bool sunny = true;

    // Checking temperature conditions using logical AND (&&) operator
    // If temperature is between 0 and 30 degrees Celsius AND it's sunny
    if (temp >= 0 && temp <= 30 && sunny) {
        printf("Temperature is acceptable\n");
    } else {
        printf("Temperature is not suitable\n");
    }

    // Checking temperature conditions using logical OR (||) operator
    // If temperature is NOT between 0 and 30 degrees Celsius OR it's not sunny
    float tempy = 15.6;
    bool sunnyy = true;

    if (tempy <= 0 || tempy >= 30 || !sunnyy) {
        printf("Temperature is not suitable\n");
    } else {
        printf("Temperature is suitable\n");
    }

    // Checking temperature conditions using logical NOT (!) operator
    // If temperature is NOT between 0 and 30 degrees Celsius
    if (!(temp >= 0 && temp <= 30)) {
        printf("Temperature is not suitable\n");
    } else {
        printf("Temperature is suitable\n");
    }

    bool shiny = false;

    if (!shiny) {
        printf("It's not sunny today\n");
    } else {
        printf("It's sunny today\n");
    }

    return 0;
}
