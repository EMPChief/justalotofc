#include <stdio.h>

// Funksjonsprototyper for bitvise operasjoner
int bitwiseAND(int a, int b);
int bitwiseOR(int a, int b);
int bitwiseXOR(int a, int b);
int leftShift(int a, int shiftBy);
int rightShift(int a, int shiftBy);

int main()
{
    // BITWISE OPERATORS = spesielle operatører brukt i bitnivåprogrammering
    // Bitvise operasjoner tillater manipulering av individuelle biter i en variabel.
    // Dette kan være nyttig i en rekke situasjoner, inkludert:
    // - Effektiv lagring og manipulering av flagg
    // - Kryptering og dekryptering av data
    // - Optimalisering av ytelse i lavnivåprogrammering og innebygde systemer
    // - Implementering av maskinvarekommunikasjon og protokoller

    // & = AND
    // | = OR
    // ^ = XOR
    // <<  venstre skift
    // >>  høyre skift
    int x = 9;  // 9 i binær: 00001001
    int y = 18; // 18 i binær: 00010010

    // AND
    // Brukes for å sette bestemte biter til 0.
    // Brukes ofte i maskinvarekommunikasjon for å maskere visse biter.
    printf("AND: %d\n", bitwiseAND(x, y));

    // OR
    // Brukes for å sette bestemte biter til 1.
    // Nyttig i situasjoner der flere flagg må kombineres i en enkelt variabel.
    printf("OR: %d\n", bitwiseOR(x, y));

    // XOR
    // Brukes for å sette bestemte biter til 1 hvis bare én av bitene er 1 (eksklusiv OR).
    // Nyttig i kryptering, feilretting, og å bytte verdier uten en midlertidig variabel.
    printf("XOR: %d\n", bitwiseXOR(x, y));

    // VENSTRE SKIFT
    // Flytter biter til venstre, og fyller de laveste bitene med 0.
    // Effektivt for å multiplisere med 2^n.
    printf("LEFT SHIFT: %d\n", leftShift(x, 2));

    // HØYRE SKIFT
    // Flytter biter til høyre, og fyller de høyeste bitene med 0 (eller 1 for negative tall).
    // Effektivt for å dele med 2^n.
    printf("RIGHT SHIFT: %d\n", rightShift(x, 2));

    return 0;
}

// Funksjon for bitvis AND
// Returnerer bit-for-bit AND av to heltall.
int bitwiseAND(int a, int b)
{
    return a & b;
}

// Funksjon for bitvis OR
// Returnerer bit-for-bit OR av to heltall.
int bitwiseOR(int a, int b)
{
    return a | b;
}

// Funksjon for bitvis XOR
// Returnerer bit-for-bit XOR av to heltall.
int bitwiseXOR(int a, int b)
{
    return a ^ b;
}

// Funksjon for venstreskift
// Skifter bitene i a til venstre med shiftBy posisjoner.
int leftShift(int a, int shiftBy)
{
    return a << shiftBy;
}

// Funksjon for høyreskift
// Skifter bitene i a til høyre med shiftBy posisjoner.
int rightShift(int a, int shiftBy)
{
    return a >> shiftBy;
}
