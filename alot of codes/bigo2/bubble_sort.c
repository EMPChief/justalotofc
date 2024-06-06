#include <stdio.h>

void bubble_sort(int array[], int size);

int main()
{
    // Definerer en array med flere tall
    int numbers[] = {5, 2, 8, 1, 9, 3, 6, 4, 99, 66, 77, 88, 55, 44, 33, 22, 11, 0};
    // Beregner antall elementer i arrayen
    int array_size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Unsorted array: ");
    // For-løkke for å gå gjennom alle elementene i arrayen og skrive dem ut
    for (int index = 0; index < array_size; index++)
    {
        printf("%d ", numbers[index]);
    }
    printf("\n");
    // Sorterer arrayen med bubble sort-algoritmen
    bubble_sort(numbers, array_size);

    printf("Sorted array: ");
    // For-løkke for å gå gjennom alle elementene i den sorterte arrayen og skrive dem ut
    for (int index = 0; index < array_size; index++)
    {
        printf("%d ", numbers[index]);
    }
    printf("\n");

    return 0;
}

void bubble_sort(int array[], int size)
{
    // For-løkke for å gjøre flere passeringer gjennom arrayen
    for (int current_pass = 0; current_pass < size - 1; current_pass++)
    {
        // For-løkke for å sammenligne og bytte elementer
        for (int current_index = 0; current_index < size - 1 - current_pass; current_index++)
        {
            // Hvis elementet ved current_index er større enn elementet ved current_index + 1
            if (array[current_index] > array[current_index + 1])
            {
                // Bytter plass på elementene
                int temp = array[current_index];
                array[current_index] = array[current_index + 1];
                array[current_index + 1] = temp;
            }
        }
    }
}
