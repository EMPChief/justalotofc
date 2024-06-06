#include <stdio.h>
#include <string.h>

int main() {
    // Bytt to verdier
    int a = 10;
    int b = 20;
    
    printf("Before swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    // Lagre verdien av 'a' i en midlertidig variabel
    int temp = a;
    printf("Assigning the value of b to a: a = %d\n", a);

    // Tildel verdien av 'b' til 'a'
    a = b;
    printf("Tildeler verdien av b til a: a = %d\n", a);

    // Tildel verdien lagret i den midlertidige variabelen til 'b'
    b = temp;
    printf("Assigning the value stored in temp to b: b = %d\n", b);

    printf("After swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // Eksempel som bruker strcpy for å kopiere strenger
    char source[] = "Hello";
    char destination[10];

    strcpy(destination, source);

    printf("\nAfter copying:\n");
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
