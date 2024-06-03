#include <stdio.h>

int main(){
    // circle circumference program
    // declare and initialize variables and constants
    const double pi = 3.14159;
    double radius;
    double circumference;
    double area;

    // get user input for radius
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    // calculate circumference of the circle
    circumference = 2 * pi * radius;
    // calculate area of the circle
    area = pi * radius * radius;
    // print results
    printf("The circumference of the circle is: %lf\n", circumference);
    printf("The area of the circle is: %lf\n", area);
    return 0;
}
