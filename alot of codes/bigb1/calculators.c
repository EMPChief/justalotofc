#include <stdio.h>
#include <stdlib.h>

int main() {
    // Calculator program using switch statement and while loop
    char operator;
    double num1, num2, result;

    while (1) {
        // Menu display
        printf("\n=== Simple Calculator ===\n");
        printf("Choose an operation (+, -, *, /, %%) or 'q' to quit: ");
        scanf(" %c", &operator);

        if (operator == 'q') {
            printf("Goodbye!\n");
            exit(0);
        }

        // Input validation
        if (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%') {
            printf("Invalid operator. Please try again.\n");
            continue;
        }

        // Input numbers
        printf("Enter the first number: ");
        scanf("%lf", &num1);
        printf("Enter the second number: ");
        scanf("%lf", &num2);

        // Perform calculation based on the chosen operator
        switch(operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero!\n");
                    continue;
                }
                result = num1 / num2;
                break;
            case '%':
                if ((int)num2 == 0) {
                    printf("Error: Modulo by zero!\n");
                    continue;
                }
                result = (int)num1 % (int)num2;
                break;
        }

        // Display result
        printf("Result: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
    }

    return 0;
}
