#include <stdio.h>
#include <string.h>

int main()
{
    // WHILE loop: Repeats a section of code as long as a specified condition remains true.
    // Note: A WHILE loop might not execute at all if the condition is false initially.

   char name[25];

   printf("\nWhat's your name?: ");
   fgets(name, 25, stdin);
   name[strlen(name) - 1] = '\0';

   while(strlen(name) == 0)
   {
      printf("\nbad guy you did not enter your name");
      printf("\nWhat's your name?: ");
      fgets(name, 25, stdin);
      name[strlen(name) - 1] = '\0';
   }

   printf("Hello %s\n", name);

   return 0;
}