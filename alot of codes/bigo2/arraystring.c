#include <stdio.h>
#include <string.h>

int main() {
    // Initialiser et tegnarray med en streng
    char name[100] = "Bjørn-Magne";
    printf("Name: %s\n", name);

    // Bestem størrelsen på name-arrayet
    size_t name_size = sizeof(name) / sizeof(name[0]);

    // Skriv ut hvert tegn i strengen med sin indeks ved bruk av en for-løkke
    printf("\nCharacters in the name array:\n");
    for (size_t nameindex = 0; nameindex < name_size; nameindex++) {
        if (name[nameindex] == '\0') {
            break;
        }
        printf("Name[%zu]: %c\n", nameindex, name[nameindex]);
    }

    // Demonstrer bruk av break-uttalelse i en løkke
    printf("\nUsing break statement in a loop:\n");
    for (size_t nameindex = 0; nameindex < name_size; nameindex++) {
        if (nameindex == 2) {
            break;
        }
        printf("Name[%zu]: %c\n", nameindex, name[nameindex]);
    }

    // Demonstrer bruk av continue-uttalelse i en løkke
    printf("\nUsing continue statement in a loop:\n");
    for (size_t nameindex = 0; nameindex < name_size; nameindex++) {
        if (nameindex == 2) {
            continue;
        }
        if (name[nameindex] == '\0') {
            break;
        }
        printf("Name[%zu]: %c\n", nameindex, name[nameindex]);
    }

    // Skriv ut hvert tegn i strengen med sin indeks ved bruk av en while-løkke
    printf("\nUsing while loop:\n");
    size_t nameindex = 0;
    while (nameindex < name_size && name[nameindex] != '\0') {
        printf("Name[%zu]: %c\n", nameindex, name[nameindex]);
        nameindex++;
    }

    // Kopier strengen til et annet array ved bruk av strcpy
    char name2[sizeof(name)];
    strcpy(name2, name);
    printf("\nCopied string using strcpy: %s\n", name2);

    return 0;
}
