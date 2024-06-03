#include <stdio.h>
#include <string.h>

int main(){
    // while loop = Repeats a section of code as long as a specified condition remains true
    // do while loop = always executes at least once, then checks the condition again

    char name[25];


    do {
        printf("\nWhat's your name?: ");
        fgets(name, 25, stdin);
        name[strlen(name) - 1] = '\0';
        if (strlen(name) == 0) {
            printf("\nYou did not enter your name.");
        }
    } while (strlen(name) == 0);

    printf("Hello %s\n", name);
    return 0;
}

/*
   // do-while loop with a counter
   int number = 0;
   int sum = 0;

   do{
      printf("Enter a # above 0: ");
      scanf("%d", &number);
      if(number > 0)
      {
         sum += number;
      }
   }while(number > 0);
   
   printf("sum: %d", sum);
 
*/