#include <stdio.h>
#include <string.h>

void happybday(char name[], int age);

int main() {
    // Learning how function works
    char name[50];
    int age;
    
    printf("Input birthday name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Input birthday age: ");
    scanf("%d", &age);
    happybday(name, age);
    return 0;
}

void happybday(char name[], int age) {
    printf("Happy birthday %s! You are %d years old!\n", name, age);
}
