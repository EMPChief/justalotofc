#include <stdio.h>

int main() {
    // 2D array = et array, hvor hvert element er et helt array
    // nyttig hvis du trenger en matrise, rutenett eller tabell med data
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Beregn antall rader i matrisen
    int number_of_rows = sizeof(matrix) / sizeof(matrix[0]);
    int number_of_columns = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    // Skriv ut alle elementer i arrayet
    for (int current_row = 0; current_row < number_of_rows; current_row++) {
        for (int current_column = 0; current_column < number_of_columns; current_column++) {
            printf("Matrix element [%d][%d]: %d\n", current_row, current_column, matrix[current_row][current_column]);
        }
    }
    
    // Multipliser alle elementer i arrayet med 2 og skriv dem ut
    for (int current_row = 0; current_row < number_of_rows; current_row++) {
        for (int current_column = 0; current_column < number_of_columns; current_column++) {
            matrix[current_row][current_column] *= 2;
            printf("Matrix element [%d][%d] etter multiplikasjon med 2: %d\n", current_row, current_column, matrix[current_row][current_column]);
        }
    }

    return 0;
}
