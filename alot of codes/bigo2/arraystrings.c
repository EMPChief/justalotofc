#include <stdio.h>
#include <string.h>

int main()
{
    // Initialiser et array av bilmerker
    char cars[][12] = {"Mustang", "Corvette", "Camaro", "Ferrari", "Porsche", "Lamborghini", "Audi", "BMW", "Mercedes", "Volvo"};

    // Beregn størrelsen på cars-arrayet
    size_t cars_size = sizeof(cars) / sizeof(cars[0]);

    // Skriv ut alle bilmerker i arrayet
    printf("Cars:\n");
    for (size_t i = 0; i < cars_size; i++)
    {
        printf("Car[%zu]: %s\n", i, cars[i]);
    }

    // Skriv ut hvert tegn i hvert bilmerke med sin indeks ved bruk av en for-løkke
    printf("\nCharacters in the cars array:\n");
    for (size_t car_index = 0; car_index < cars_size; car_index++)
    {
        printf("Car[%zu]: %s\n", car_index, cars[car_index]);
        size_t car_length = strlen(cars[car_index]);
        for (size_t char_index = 0; char_index < car_length; char_index++)
        {
            printf("  Character[%zu]: %c\n", char_index, cars[car_index][char_index]);
        }
    }

    // Demonstrer bruk av break-uttalelse i en løkke
    printf("\nUsing break statement in a loop:\n");
    for (size_t car_index = 0; car_index < cars_size; car_index++)
    {
        if (car_index == 2)
        {
            break;
        }
        printf("Car[%zu]: %s\n", car_index, cars[car_index]);
    }

    // Demonstrer bruk av continue-uttalelse i en løkke
    printf("\nUsing continue statement in a loop:\n");
    for (size_t car_index = 0; car_index < cars_size; car_index++)
    {
        if (car_index == 2)
        {
            continue;
        }
        printf("Car[%zu]: %s\n", car_index, cars[car_index]);
    }

    // Skriv ut hvert bilmerke med sin indeks ved bruk av en while-løkke
    printf("\nUsing while loop:\n");
    size_t car_index = 0;
    while (car_index < cars_size)
    {
        printf("Car[%zu]: %s\n", car_index, cars[car_index]);
        car_index++;
    }

    // Kopier et bilmerke til et annet array ved bruk av strcpy
    char car_copy[10];
    strcpy(car_copy, cars[0]);
    printf("\nCopied car using strcpy: %s\n", car_copy);

    // Oppdater det første elementet til "Tesla"
    strcpy(cars[0], "Tesla");

    // Skriv ut alle bilmerker i arrayet etter oppdatering
    printf("\nUpdated Cars array:\n");
    for (size_t i = 0; i < cars_size; i++)
    {
        printf("Car[%zu]: %s\n", i, cars[i]);
    }

    return 0;
}
