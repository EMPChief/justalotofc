#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Funksjon for å telle antall ord i filen
int countWordsInFile(FILE *filePointer);

// Funksjon for å lese ord fra filen og lagre dem i buffer
void readWordsFromFile(FILE *filePointer, char **buffer, int wordCount);

int main()
{
    // Åpner en fil for skriving ("w" - skrive modus)
    FILE *filePointer1 = fopen("test.txt", "w");
    if (filePointer1 == NULL)
    {
        printf("File open error\n");
        return 1;
    }

    // Skriver noen tekstlinjer til filen
    fprintf(filePointer1, "Hello, World!\n");
    fprintf(filePointer1, "This is a test file.\n");
    fprintf(filePointer1, "I love C!\n");
    fclose(filePointer1);

    // Fjerner filen "test.txt"
    if (remove("testxc.txt") == 0)
    {
        printf("File removed successfully\n");
    }
    else
    {
        printf("File removal failed\n");
    }

    // Åpner en ny fil for både lesing og skriving ("w+" - skrive og lese modus)
    FILE *filePointer2 = fopen("teststy.txt", "w+");
    if (filePointer2 == NULL)
    {
        printf("File open error\n");
        return 1;
    }

    // Skriver noen tekstlinjer til filen
    fprintf(filePointer2, "Hello, World!\n");
    fprintf(filePointer2, "This is a test file.\n");
    fprintf(filePointer2, "I love C!\n");
    rewind(filePointer2); // Tilbakestill filpekeren til begynnelsen av filen

    // Telle antall ord i filen
    int wordCount = countWordsInFile(filePointer2);
    rewind(filePointer2); // Tilbakestill filpekeren til begynnelsen av filen

    // Allokere buffer for å lagre ordene
    char **buffer = (char **)malloc(wordCount * sizeof(char *));
    if (buffer == NULL)
    {
        printf("Memory allocation error\n");
        fclose(filePointer2);
        return 1;
    }

    // Lese ordene fra filen inn i bufferet
    readWordsFromFile(filePointer2, buffer, wordCount);

    // Skrive ut ordene som er lagret i bufferet
    printf("Read words from file: \n");
    for (int i = 0; i < wordCount; i++)
    {
        printf("%s\n", buffer[i]);
        free(buffer[i]); // Frigjøre hver enkelt ord
    }
    free(buffer); // Frigjøre bufferet

    fclose(filePointer2);
    return 0;
}

// Funksjon for å telle antall ord i filen
int countWordsInFile(FILE *filePointer)
{
    int count = 0;
    char ch;
    int inWord = 0;

    while ((ch = fgetc(filePointer)) != EOF)
    {
        if (isspace(ch))
        {
            inWord = 0;
        }
        else if (!inWord)
        {
            inWord = 1;
            count++;
        }
    }
    return count;
}

// Funksjon for å lese ord fra filen og lagre dem i buffer
void readWordsFromFile(FILE *filePointer, char **buffer, int wordCount)
{
    int index = 0;
    char word[100];

    while (fscanf(filePointer, "%99s", word) == 1)
    {
        buffer[index] = (char *)malloc((strlen(word) + 1) * sizeof(char));
        if (buffer[index] == NULL)
        {
            printf("Memory allocation error\n");
            exit(1);
        }
        strcpy(buffer[index], word);
        index++;
    }
}
