#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Definerer en typedef-struktur for en bruker
typedef struct
{
    char name[50];
    char password[50];
    char email[100];
    int age;
    char number[20];
    int id;
} User;

// Funksjonsprototyper
void printUserInfo(User user);
User findOldestUser(User users[], int size);
int isEmailValid(const char *email);

int main()
{
    // Initialiserer brukere
    User users[4] = {
        {"John", "ASDASD23", "john@gmail.com", 37, "1234567890", 1},
        {"Jane", "KllYOUMt12", "jane@gmailcom", 21, "1234567890", 2},
        {"Bob", "Shutyafkingmouth12", "bob@gmail.com", 42, "1234567890", 3},
        {"Alice", "YOuareAfkingHore", "alicegmail.com", 27, "1234567890", 4}};

    // Skriver ut brukerinfo
    for (int userIndex = 0; userIndex < 4; userIndex++)
    {
        printUserInfo(users[userIndex]);
    }

    // Finner og skriver ut den eldste brukeren
    User oldestUser = findOldestUser(users, 4);
    printf("Oldest User:\n");
    printUserInfo(oldestUser);

    // Validerer e-postadresser
    for (int userIndex = 0; userIndex < 4; userIndex++)
    {
        if (isEmailValid(users[userIndex].email))
        {
            printf("Email %s is valid.\n", users[userIndex].email);
        }
        else
        {
            printf("Email %s is not valid.\n", users[userIndex].email);
        }
    }

    return 0;
}

// Funksjon for å skrive ut brukerinfo
void printUserInfo(User user)
{
    printf("User %d:\n", user.id);
    printf("Name: %s\n", user.name);
    printf("Password: %s\n", user.password);
    printf("Email: %s\n", user.email);
    printf("Age: %d\n", user.age);
    printf("Number: %s\n", user.number);
    printf("ID: %d\n", user.id);
    printf("\n");
}

// Funksjon for å finne den eldste brukeren
User findOldestUser(User users[], int size)
{
    User oldestUser = users[0];
    for (int index = 1; index < size; index++)
    {
        if (users[index].age > oldestUser.age)
        {
            oldestUser = users[index];
        }
    }
    return oldestUser;
}

// Funksjon for å sjekke om en e-postadresse er gyldig
int isEmailValid(const char *email)
{
    const char *atSign = strchr(email, '@');
    if (!atSign || atSign == email || strchr(atSign, '.') == NULL)
    {
        return 0;
    }
    return 1;
}