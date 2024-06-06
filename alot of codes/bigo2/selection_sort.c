#include <stdio.h>

void selection_sort(int array[], int size);

int main()
{
    // Definerer en array med 18 tall
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
    // Sorterer arrayen med selection sort-algoritmen
    selection_sort(numbers, array_size);

    printf("Sorted array: ");
    // For-løkke for å gå gjennom alle elementene i arrayen og skrive dem ut
    for (int index = 0; index < array_size; index++)
    {
        printf("%d ", numbers[index]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int array[], int size)
{
    // For-løkke for å gå gjennom alle elementene i arrayen
    for (int current_index = 0; current_index < size - 1; current_index++)
    {
        // For-løkke for å sammenligne det nåværende elementet med de resterende elementene
        for (int next_index = current_index + 1; next_index < size; next_index++)
        {
            // Hvis det nåværende elementet er større enn neste element
            if (array[current_index] > array[next_index])
            {
                // Bytt plass på de to elementene
                int temp = array[current_index];
                array[current_index] = array[next_index];
                array[next_index] = temp;
            }
        }
    }
}
