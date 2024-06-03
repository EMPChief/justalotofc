#include <stdio.h>
#include <ctype.h>

int main() {
    // Temperature converter
    char unit;
    float temp;

    printf("What unit do you want to convert to? (F or C) ");
    scanf(" %c", &unit);

    unit = toupper(unit);

    if (unit == 'F') {
        printf("Enter the temperature in C: ");
        scanf("%f", &temp);
        temp = (temp * 9 / 5) + 32;
        printf("Temperature in Fahrenheit: %.2f\n", temp);
    } else if (unit == 'C') {
        printf("Enter the temperature in F: ");
        scanf("%f", &temp);
        temp = (temp - 32) * 5 / 9;
        printf("Temperature in Celsius: %.2f\n", temp);
    } else {
        printf("Invalid Input\n");
    }
    return 0;
}
