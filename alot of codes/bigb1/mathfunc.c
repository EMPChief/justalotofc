#include <stdio.h>
#include <math.h>

int main(){
    // Some basic math functions
    
    // Get the square root of a number:
    double A = sqrt(18);
    printf("Square Root of 18: %f\n", A);
    
    // Looks for the power of 10 to the power of 36 (10^36) :
    double B = pow(10, 36);
    printf("Power of 10 to 36: %f\n", B);
    
    // Natural logarithm of a number (returns base e logarithm): 
    double G = log(10);
    printf("Natural Logarithm of 10: %f\n", G);
    
    // Rounding to the nearest integer:
    int C = round(10.5712);
    printf("Rounded value of 10.5712: %d\n", C);
    
    // Raise to the nearest integer:
    int D = ceil(10.5712);
    printf("Ceiling of 10.5712: %d\n", D);
    
    // Lower to the nearest integer:
    int E = floor(10.5712);
    printf("Floor of 10.5712: %d\n", E);
    
    // Finds the absolute value of a number:
    double F = fabs(-10.5712);
    printf("Absolute value of -10.5712: %f\n", F);
    
    // Finds the sine of an angle in radians:
    double H = sin(45);
    printf("Sine of 45 degrees: %f\n", H);
    
    // Finds the cosine of an angle in radians:
    double I = cos(45);
    printf("Cosine of 45 degrees: %f\n", I);
    
    // Finds the tangent of an angle in radians:
    double J = tan(45);
    printf("Tangent of 45 degrees: %f\n", J);
    
    return 0;
}
