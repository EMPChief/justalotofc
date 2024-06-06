#include <stdio.h>

void bubble_sort(char array[], int size);

int main()
{
    // Definerer en array med flere tegn
    char alphabet[] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    // Beregner antall elementer i arrayen
    int array_size = sizeof(alphabet) / sizeof(alphabet[0]);

    printf("Unsorted array: ");
    // For-løkke for å gå gjennom alle elementene i arrayen og skrive dem ut
    for (int index = 0; index < array_size; index++)
    {
        printf("%c ", alphabet[index]);
    }
    printf("\n");
    // Sorterer arrayen med bubble sort-algoritmen
    bubble_sort(alphabet, array_size);

    printf("Sorted array: ");
    // For-løkke for å gå gjennom alle elementene i den sorterte arrayen og skrive dem ut
    for (int index = 0; index < array_size; index++)
    {
        printf("%c ", alphabet[index]);
    }
    printf("\n");

    return 0;
}

void bubble_sort(char array[], int size)
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
                char temp = array[current_index];
                array[current_index] = array[current_index + 1];
                array[current_index + 1] = temp;
            }
        }
    }
}
