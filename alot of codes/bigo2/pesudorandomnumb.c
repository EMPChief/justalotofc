#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funksjonsprototyper
int generateRandomNumber(int minValue, int maxValue);

int main()
{
   // pseudo random numbers = A set of values or elements that is statistically random
   //                         (Don't use these for any sort of cryptographic security)

   // Initialiserer random number generator med nåværende tid som seed
   srand(time(0));

   // Antall tilfeldige tall som skal genereres
   const int numberOfRandomNumbers = 9;
   const int minValue = 1;
   const int maxValue = 120;

   // Genererer og skriver ut tre tilfeldige tall mellom 1 og 60
   for (int currentIndex = 0; currentIndex < numberOfRandomNumbers; currentIndex++)
   {
      int randomNumber = generateRandomNumber(minValue, maxValue);
      printf("Random Number %d: %d\n", currentIndex + 1, randomNumber);
   }

   return 0;
}

// Funksjon for å generere et tilfeldig tall innenfor et gitt intervall
int generateRandomNumber(int minValue, int maxValue)
{
   return (rand() % (maxValue - minValue + 1)) + minValue;
}
