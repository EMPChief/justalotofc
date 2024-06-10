#include <stdio.h>
#include <string.h>

// Definerer en struktur for en student
struct Student
{
    char name[30];
    int age;
    float gpa;
    char class[10];
};

// Funksjonsprototyper
void printStudentInfo(struct Student student);
float calculateAverageGPA(struct Student students[], int size);
struct Student findHighestGPAStudent(struct Student students[], int size);

int main()
{
    // Initialiserer studenter med en initializer liste
    struct Student students[] = {
        {"Bjorn", 20, 3.5, "1A"},
        {"Magne", 21, 3.9, "1B"},
        {"Ole", 22, 3.2, "1C"},
        {"Kristin", 23, 3.7, "1D"},
        {"Tore", 24, 3.1, "1E"},
        {"Kari", 25, 3.6, "1F"},
        {"Frida", 19, 2.2, "1C"},
    };

    int numStudents = sizeof(students) / sizeof(students[0]);

    // Skriver ut informasjon om alle studentene
    printf("Students:\n");
    for (int index = 0; index < numStudents; index++)
    {
        printf("Student[%d]:\n", index);
        printStudentInfo(students[index]);
    }

    // Beregner og skriver ut gjennomsnittlig GPA
    float averageGPA = calculateAverageGPA(students, numStudents);
    printf("Average GPA: %.2f\n\n", averageGPA);

    // Finner og skriver ut studenten med høyest GPA
    struct Student highestGPAStudent = findHighestGPAStudent(students, numStudents);
    printf("Student with the highest GPA:\n");
    printStudentInfo(highestGPAStudent);

    return 0;
}

// Funksjon for å skrive ut studentinfo
void printStudentInfo(struct Student student)
{
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("GPA: %.2f\n", student.gpa);
    printf("Class: %s\n", student.class);
    printf("\n");
}

// Funksjon for å beregne gjennomsnittlig GPA
float calculateAverageGPA(struct Student students[], int size)
{
    float totalGPA = 0.0;
    for (int index = 0; index < size; index++)
    {
        totalGPA += students[index].gpa;
    }
    return totalGPA / size;
}

// Funksjon for å finne studenten med høyest GPA
struct Student findHighestGPAStudent(struct Student students[], int size)
{
    struct Student highestGPAStudent = students[0];
    for (int index = 1; index < size; index++)
    {
        if (students[index].gpa > highestGPAStudent.gpa)
        {
            highestGPAStudent = students[index];
        }
    }
    return highestGPAStudent;
}
