#include <stdio.h>
#include <math.h>

int main(){
    // hypotenuse calculator program
    // declare and initialize variables
    double a;
    double b;
    double c;

    // get user input for side lengths
    printf("Enter the length of the first side: ");
    scanf("%lf", &a);
    printf("Enter the length of the second side: ");
    scanf("%lf", &b);

    // calculate the length of the hypotenuse
    c = sqrt(a*a + b*b);
    printf("The length of the hypotenuse is: %lf\n", c);
    return 0;
}
