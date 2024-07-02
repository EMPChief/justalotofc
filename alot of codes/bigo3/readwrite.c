#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Åpner en fil for skriving ("w" - skrive modus)
    FILE *filePointer1 = fopen("test.txt", "w");
    if (filePointer1 == NULL)
    {
        // Feil ved åpning av fil. Hvis filen ikke kan åpnes, skrives en feilmelding.
        printf("File open error\n");
        return 1;
    }

    // Skriver tekstlinjer til filen ved hjelp av fprintf
    fprintf(filePointer1, "Hello, World!\n");
    fprintf(filePointer1, "This is a test file.\n");
    fprintf(filePointer1, "I love C!\n");
    // Lukker filen etter skriving for å frigjøre ressursene
    fclose(filePointer1);

    // Fjerner filen "test.txt" fra filsystemet
    if (remove("test.txt") == 0)
    {
        // Suksessmelding ved vellykket fjerning
        printf("File removed successfully\n");
    }
    else
    {
        // Feilmelding hvis filen ikke kunne fjernes
        printf("File removal failed\n");
    }

    // Åpner en ny fil for både lesing og skriving ("w+" - skrive og lese modus)
    FILE *filePointer2 = fopen("testy.txt", "w+");
    if (filePointer2 == NULL)
    {
        // Feil ved åpning av fil. Hvis filen ikke kan åpnes, skrives en feilmelding.
        printf("File open error\n");
        return 1;
    }

    // Skriver tekstlinjer til filen ved hjelp av fprintf
    fprintf(filePointer2, "Hello, World!\n");
    fprintf(filePointer2, "This is a test file.\n");
    fprintf(filePointer2, "I love C!\n");

    // Tilbakestiller filpekeren til begynnelsen av filen
    // Dette er nødvendig for å kunne lese innholdet fra starten
    rewind(filePointer2);

    // Allokere buffer dynamisk for å lagre innholdet som leses fra filen
    char *buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL)
    {
        // Feil ved allokering av minne
        printf("Memory allocation error\n");
        fclose(filePointer2);
        return 1;
    }

    // Leser data fra filen inn i bufferet
    // fread returnerer antall elementer (bytes) som ble lest
    size_t bytesRead = fread(buffer, sizeof(char), 100, filePointer2);
    if (bytesRead > 0)
    {
        // Suksessmelding ved vellykket lesing og skriver det leste innholdet til standard utgang (stdout)
        printf("Read from file: \n");
        // fwrite skriver bufferet til standard utgang (konsollen) basert på antall bytes som ble lest
        fwrite(buffer, sizeof(char), bytesRead, stdout);
    }
    else
    {
        // Feilmelding hvis det oppstår en feil ved lesing av filen
        printf("File read error\n");
    }

    // Frigjør den dynamisk allokerte minnet
    free(buffer);

    // Lukker filen etter lesing og skriving for å frigjøre ressursene
    fclose(filePointer2);
    return 0;
}
