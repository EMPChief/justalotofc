#include <stdio.h>

// Definerer en enum for dager i uken
enum Day
{
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};

// Funksjonsprototyper
enum Day addDays(enum Day currentDay, int daysToAdd);
int daysUntilWeekend(enum Day currentDay);

int main()
{
    // enum = a user defined type of named integer identifiers
    //               helps to make a program more readable

    enum Day today = Saturday;

    printf("Today is %d\n", today);

    if (today == Sunday || today == Saturday)
    {
        printf("It's the weekend!\n");
    }
    else
    {
        printf("It's a work day!\n");
    }

    // Legg til dager og finn den nye dagen
    int daysToAdd = 3;
    enum Day newDay = addDays(today, daysToAdd);
    printf("In %d days, it will be day %d\n", daysToAdd, newDay);

    // Beregn antall dager til helgen
    int daysToWeekend = daysUntilWeekend(today);
    printf("There are %d days until the weekend.\n", daysToWeekend);

    return 0;
}

// Funksjon for å legge til et antall dager til en gitt dag
enum Day addDays(enum Day currentDay, int daysToAdd)
{
    int newDay = (currentDay + daysToAdd - 1) % 7 + 1;
    return (enum Day)newDay;
}

// Funksjon for å beregne antall dager til helgen
int daysUntilWeekend(enum Day currentDay)
{
    if (currentDay == Saturday || currentDay == Sunday)
    {
        return 0;
    }
    return Saturday - currentDay;
}
