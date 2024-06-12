#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funksjonsprototyper
void initializeRandomNumberGenerator();
int generateRandomNumber(int minValue, int maxValue);
void playGuessingGame(int minValue, int maxValue, int maxAttempts);
void printResult(int correctAnswer, int numberOfGuesses);

int main()
{
    // Setter variabler for gjetting av tall
    const int minValue = 1;
    const int maxValue = 100;
    const int maxAttempts = 10;

    // Initialiserer random number generator
    initializeRandomNumberGenerator();

    // Starter gjettespillet
    playGuessingGame(minValue, maxValue, maxAttempts);

    return 0;
}

// Initialiserer random number generator med nåværende tid som seed
void initializeRandomNumberGenerator()
{
    srand(time(0));
}

// Genererer et tilfeldig tall innenfor et gitt intervall
int generateRandomNumber(int minValue, int maxValue)
{
    return (rand() % (maxValue - minValue + 1)) + minValue;
}

// Starter gjettespillet
void playGuessingGame(int minValue, int maxValue, int maxAttempts)
{
    int correctAnswer = generateRandomNumber(minValue, maxValue);
    int userGuess = 0;
    int numberOfGuesses = 0;

    printf("Guess the number between %d and %d. You have %d attempts.\n", minValue, maxValue, maxAttempts);

    while (numberOfGuesses < maxAttempts)
    {
        printf("Attempt %d: ", numberOfGuesses + 1);
        scanf("%d", &userGuess);

        if (userGuess > correctAnswer)
        {
            printf("Too high. Try again.\n");
        }
        else if (userGuess < correctAnswer)
        {
            printf("Too low. Try again.\n");
        }
        else
        {
            printf("Correct! You guessed it in %d attempts.\n", numberOfGuesses + 1);
            break;
        }

        numberOfGuesses++;
    }

    if (userGuess != correctAnswer)
    {
        printf("You've used all %d attempts. The correct answer was %d.\n", maxAttempts, correctAnswer);
    }

    printResult(correctAnswer, numberOfGuesses);
}

// Skriver ut resultatet
void printResult(int correctAnswer, int numberOfGuesses)
{
    printf("**************\n");
    printf("Answer: %d\n", correctAnswer);
    printf("Total guesses: %d\n", numberOfGuesses);
    printf("**************\n");
}
