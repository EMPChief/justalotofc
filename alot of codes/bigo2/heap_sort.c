#include <stdio.h>

void heapify(int array[], int size, int root_index);
void heap_sort(int array[], int size);

int main()
{
    // Heap sort = en sorteringsalgoritme som brukes til å sortere data i en heap-struktur
    int numbers[] = {5, 2, 8, 1, 9, 3, 6, 4, 99, 66, 77, 88, 55, 44, 33, 22, 11, 0};
    // Array size = antall elementer i arrayet
    int array_size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Unsorted array: ");
    // skriv ut elementer i arrayet
    for (int index = 0; index < array_size; index++)
    {
        printf("%d ", numbers[index]);
    }
    printf("\n");
    // Sort the array
    heap_sort(numbers, array_size);

    printf("Sorted array: ");
    // skriv ut sorterte elementer
    for (int index = 0; index < array_size; index++)
    {
        printf("%d ", numbers[index]);
    }
    printf("\n");

    return 0;
}

void heapify(int array[], int size, int root_index)
{
    // Heapify = en funksjon som sørger for at en del av heap-strukturen er sortert
    int largest_index = root_index;
    int left_child_index = 2 * root_index + 1;
    int right_child_index = 2 * root_index + 2;

    // Sjekker om venstre barn er større enn roten
    if (left_child_index < size && array[left_child_index] > array[largest_index])
    {
        largest_index = left_child_index;
    }
    // Sjekker om høyre barn er større enn nåværende største element
    if (right_child_index < size && array[right_child_index] > array[largest_index])
    {
        largest_index = right_child_index;
    }
    // Hvis største element ikke er roten, bytt dem og heapify sub-treet
    if (largest_index != root_index)
    {
        int temp = array[root_index];
        array[root_index] = array[largest_index];
        array[largest_index] = temp;

        heapify(array, size, largest_index);
    }
}

void heap_sort(int array[], int size)
{
    // Heap sort = en sorteringsalgoritme som brukes til å sortere data i en heap-struktur
    // Bygg maks-heap
    for (int start_index = size / 2 - 1; start_index >= 0; start_index--)
    {
        heapify(array, size, start_index);
    }
    // Trekk elementene fra heapen en etter en og sorter arrayet
    for (int end_index = size - 1; end_index > 0; end_index--)
    {
        int temp = array[0];
        array[0] = array[end_index];
        array[end_index] = temp;

        heapify(array, end_index, 0);
    }
}
