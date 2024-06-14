#include <stdio.h>

// Funksjonsprototyper for bitvise operasjoner
int bitwiseAND(int a, int b);
int bitwiseOR(int a, int b);
int bitwiseXOR(int a, int b);
int leftShift(int a, int shiftBy);
int rightShift(int a, int shiftBy);

int main()
{
    // BITWISE OPERATORS = special operators used in bit-level programming
    // Bitwise operations allow manipulation of individual bits in a variable.
    // This can be useful in a variety of situations, including:
    // - Efficient storage and manipulation of flags
    // - Encryption and decryption of data
    // - Performance optimization in low-level programming and embedded systems
    // - Implementation of hardware communication and protocols

    // & = AND
    // | = OR
    // ^ = XOR
    // << = left shift
    // >> = right shift
    int x = 9;
    int y = 18;

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
