#include <stdio.h>

int main()
{
    // nested loops - loop inside another loop
    int rows, cols;
    char symbol;
    printf("Input number of rows: ");
    scanf("%d", &rows);

    printf("Input number of columns: ");
    scanf("%d", &cols);

    printf("Input symbol: ");
    scanf(" %c", &symbol);
    
    for (int inner = 0; inner < rows; inner++)
    {
        for (int outer = 0; outer < cols; outer++)
        {
            printf("%c ", symbol);
        }
        printf("\n");
    }

    return 0;
}

/*
int rows;
   int columns;
   char symbol;

   printf("\nEnter # of rows: ");
   scanf("%d", &rows);

   printf("Enter # of columns: ");
   scanf("%d", &columns);

   scanf("%c"); //clears \n from buffer

   printf("Enter a symbol to use: ");
   scanf("%c", &symbol);

   for(int i = 1; i <= rows; i++)
   {
      for(int j = 1; j <= columns; j++)
      {
         printf("%d", j);
      }
      printf("\n");
   }
*/