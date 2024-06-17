#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setter variabler for gjetting av tall
    const int minValue = 1;
    const int maxValue = 100;
    int userGuess = 0;
    int numberOfGuesses = 0;
    int correctAnswer = 0;

    // Initialiserer random number generator med nåværende tid som seed
    srand(time(0));

    // Lager et tilfeldig tall mellom minValue og maxValue
    correctAnswer = (rand() % (maxValue - minValue + 1)) + minValue;

    do
    {
        printf("Guess a number between %d and %d: ", minValue, maxValue);
        scanf("%d", &userGuess);

        if (userGuess > correctAnswer)
        {
            printf("Too high. Try again.\n");
            printf("You guessed %d\n", userGuess);
        }
        else if (userGuess < correctAnswer)
        {
            printf("Too low. Try again.\n");
            printf("You guessed %d\n", userGuess);
        }
        else
        {
            printf("Correct! You guessed it in %d attempts.\n", numberOfGuesses + 1);
        }
        numberOfGuesses++;
    } while (userGuess != correctAnswer);

    printf("**************\n");
    printf("Answer: %d\n", correctAnswer);
    printf("Total attempts: %d\n", numberOfGuesses);
    printf("**************\n");

    return 0;
}
