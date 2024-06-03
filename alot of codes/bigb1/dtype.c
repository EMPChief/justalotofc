#include <stdio.h>
#include <stdbool.h>

int main() {
    char a = 'a';                                       // declare and initialize a single character (1 byte) (-128 to 127 %d or %c)
    char b[] = "hello";                                 // declare and initialize a string of characters and store it in an array (6 bytes including null terminator) (just an array %s)
    float c = 3.14;                                     // declare and initialize a single-precision floating-point number (4 bytes) (6 - 7 digits %f)
    int d = 42;                                         // declare and initialize an integer (4 bytes) (6 - 7 digits %d)
    double e = 3.14159;                                 // declare and initialize a double-precision floating-point number (8 bytes) (15 - 16 digits %lf)
    int f = 1;                                          // declare and initialize an integer for boolean value (1 for true, 0 for false) (4 bytes) (1 digit %d)
    char e_value = 100;                                 // declare and initialize a character with an integer value (1 byte)(-128 to 127 %d or %c)
    int fk = 1;                                         // short or long dont need to be initialized with int or char
    unsigned char g = 255;                              // declare and initialize an unsigned character with an integer value (1 byte) (0 to 255 %d or %c)
    short int h = 32767;                                // declare and initialize a short integer with an integer value (2 bytes) (-32768 to 32767 %d)
    unsigned short int i = 65535;                       // declare and initialize an unsigned short integer with an integer value (2 bytes) (0 to 65535 %d)
    long int j = 2147483647;                            // declare and initialize a long integer with an integer value (4 bytes) (-2147483648 to 2147483647 %d)
    unsigned long int k = 4294967295;                   // declare and initialize an unsigned long integer with an integer value (4 bytes) (0 to 4294967295 %d)
    long long int l = 9223372036854775807;              // declare and initialize a long long integer with an integer value (8 bytes) (-9223372036854775808 to 9223372036854775807 %lld)
    unsigned long long int m = 18446744073709551615ULL; // declare and initialize an unsigned long long integer with an integer value (8 bytes) (0 to 18446744073709551615 %d)
    bool n = true;                                      // declare and initialize a boolean value (1 byte) (1 for true, 0 for false (1 digit %d))
    bool o = false;                                     // declare and initialize a boolean value (1 byte) (1 for true, 0 for false (1 digit %d))
    
    // Print the values of each variable
    printf("a = %c (%zu bytes)\n", a, sizeof(a));                        // print the value of a (character)
    printf("b = %s (%zu bytes)\n", b, sizeof(b));                        // print the value of b (string)
    printf("c = %.2f (%zu bytes)\n", c, sizeof(c));                      // print the value of c (float) with 2 decimal places
    printf("d = %d (%zu bytes)\n", d, sizeof(d));                        // print the value of d (integer)
    printf("e = %.5lf (%zu bytes)\n", e, sizeof(e));                     // print the value of e (double) with 5 decimal places
    printf("f = %d (%zu bytes)\n", f, sizeof(f));                        // print the value of f (boolean, represented as an integer)
    printf("e_value = %c (%zu bytes)\n", e_value, sizeof(e_value));      // print the value of e_value (character)
    printf("g = %hhu (%zu bytes)\n", g, sizeof(g));                      // print the value of g (unsigned character)
    printf("h = %hd (%zu bytes)\n", h, sizeof(h));                       // print the value of h (short integer)
    printf("i = %hu (%zu bytes)\n", i, sizeof(i));                       // print the value of i (unsigned short integer)
    printf("j = %ld (%zu bytes)\n", j, sizeof(j));                       // print the value of j (long integer)
    printf("k = %lu (%zu bytes)\n", k, sizeof(k));                       // print the value of k (unsigned long integer)
    printf("l = %lld (%zu bytes)\n", l, sizeof(l));                      // print the value of l (long long integer)
    printf("m = %llu (%zu bytes)\n", m, sizeof(m));                      // print the value of m (unsigned long long integer)
    printf("n = %s (%zu bytes)\n", n ? "true" : "false", sizeof(n));     // print the value of n (boolean, represented as a string)
    printf("o = %s (%zu bytes)\n", o ? "true" : "false", sizeof(o));     // print the value of o (boolean, represented as a string)
    
    // format specifier % = defines and format a type of data to be displayed
    // %c = character
    // %s = string
    // %f = float
    // %d = integer
    // %.1 = decimals precision
    // %1 = minimum field width
    // %- = left align
    // %+ = right align
    // %lf = double
    // %hhu = unsigned character
    // %hd = short integer
    // %hu = unsigned short integer
    // %ld = long integer
    // %lu = unsigned long integer
    // %lld = long long integer
    // %llu = unsigned long long integer
    // %d = boolean, represented as an integer
    // %d = boolean, represented as an integer
    
    float item1 = 5.75;
    float item2 = 10.00;
    float item3 = 100.99;

    printf("Item 1: $%8.2f\n", item1);
    printf("Item 2: $%8.2f\n", item2);
    printf("Item 3: $%8.2f\n", item3);


    return 0;
}
