#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int countSentencesInFile(FILE *filePointer);
void readSentencesFromFile(FILE *filePointer, char **buffer, int sentenceCount);

int main()
{
    // Open a file for writing ("w" - write mode)
    FILE *filePointer1 = fopen("test.txt", "w");
    if (filePointer1 == NULL)
    {
        printf("File open error\n");
        return 1;
    }

    // Write some text lines to the file
    fprintf(filePointer1, "Hello, World!\n");
    fprintf(filePointer1, "This is a test file.\n");
    fprintf(filePointer1, "I love C!\n");
    fclose(filePointer1);

    // Remove the file "test.txt"
    if (remove("test.txt") == 0)
    {
        printf("File removed successfully\n");
    }
    else
    {
        printf("File removal failed\n");
    }

    // Open a new file for both reading and writing ("w+" - write and read mode)
    FILE *filePointer2 = fopen("testy.txt", "w+");
    if (filePointer2 == NULL)
    {
        printf("File open error\n");
        return 1;
    }

    // Write some text lines to the file
    fprintf(filePointer2, "Hello, World!\n");
    fprintf(filePointer2, "This is a test file.\n");
    fprintf(filePointer2, "I love C!\n");
    rewind(filePointer2); // Reset file pointer to the beginning of the file

    // Count the number of sentences in the file
    int sentenceCount = countSentencesInFile(filePointer2);
    rewind(filePointer2); // Reset file pointer to the beginning of the file

    // Allocate buffer to store sentences
    char **buffer = (char **)malloc(sentenceCount * sizeof(char *));
    if (buffer == NULL)
    {
        printf("Memory allocation error\n");
        fclose(filePointer2);
        return 1;
    }

    // Read sentences from the file into the buffer
    readSentencesFromFile(filePointer2, buffer, sentenceCount);

    // Print the sentences read from the file
    printf("Read sentences from file:\n");
    for (int i = 0; i < sentenceCount; i++)
    {
        printf("%s\n", buffer[i]);
        free(buffer[i]); // Free each sentence
    }
    free(buffer); // Free the buffer

    fclose(filePointer2);
    return 0;
}

// Function to count the number of sentences in the file
int countSentencesInFile(FILE *filePointer)
{
    int count = 0;
    char ch;

    while ((ch = fgetc(filePointer)) != EOF)
    {
        if (ch == '.' || ch == '!' || ch == '?')
        {
            count++;
        }
    }
    return count;
}

// Function to read sentences from the file and store them in buffer
void readSentencesFromFile(FILE *filePointer, char **buffer, int sentenceCount)
{
    int index = 0;
    char sentence[1000];

    while (fgets(sentence, sizeof(sentence), filePointer) != NULL)
    {
        // Remove newline character at the end, if present
        sentence[strcspn(sentence, "\n")] = '\0';

        buffer[index] = (char *)malloc((strlen(sentence) + 1) * sizeof(char));
        if (buffer[index] == NULL)
        {
            printf("Memory allocation error\n");
            exit(1);
        }
        strcpy(buffer[index], sentence);
        index++;
    }
}
