#include <stdio.h>
#include <string.h>

// Definisjon av 'player'-strukturen
struct player
{
    char name[100];
    int age;
    float score;
};

int main()
{
    // struct = collection of related members ("variables")
    //          they can be of different data types
    //          listed under one name in a block of memory
    //          VERY SIMILAR to classes in other languages (but no methods)

    // Opprett to instanser av 'player'-strukturen
    struct player player1;
    struct player player2;

    // Initialiser player1
    strcpy(player1.name, "Bjørn-Magne");
    player1.age = 25;
    player1.score = 82.72;

    // Initialiser player2
    strcpy(player2.name, "Frida Vilhelmine");
    player2.age = 27;
    player2.score = 95.75;

    // Skriv ut detaljer om player1
    printf("Player 1:\n");
    printf("Name: %s\n", player1.name);
    printf("Age: %d\n", player1.age);
    printf("Score: %.2f\n\n", player1.score);

    // Skriv ut detaljer om player2
    printf("Player 2:\n");
    printf("Name: %s\n", player2.name);
    printf("Age: %d\n", player2.age);
    printf("Score: %.2f\n\n", player2.score);

    // Beregn og vis gjennomsnittlig score
    float averageScore = (player1.score + player2.score) / 2;
    printf("Average Score of Player 1 and Player 2: %.2f\n\n", averageScore);

    // Sammenlign score og vis resultatet
    if (player1.score > player2.score)
    {
        printf("%s has a higher score than %s.\n", player1.name, player2.name);
    }
    else if (player1.score < player2.score)
    {
        printf("%s has a higher score than %s.\n", player2.name, player1.name);
    }
    else
    {
        printf("%s and %s have the same score.\n", player1.name, player2.name);
    }

    return 0;
}
