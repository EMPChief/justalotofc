#include <stdio.h>
#include <cs50.h>

int main(void){
    string username = get_string("Username: ");
    int age = get_int("Age: ");
    
    if (age >= 80){
        printf("Hello you are to old to be here\n");
    } else if (age <= 0){
        printf("Liar! you have not been born!\n");
    } else if (age <= 13){
        printf("You are too young to be here\n");
    } else if (age >= 18){
        printf("Welcome, %s!\n", username);
    } else{
        printf("Access Denied!\n");
    }
    return 0;
}
/*
#include <stdio.h>

int main(void) {
    char username[50];
    int age;

    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    
    printf("Age: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("Welcome, %s!\n", username);
    } else {
        printf("Access Denied!\n");
    }

    return 0;
}

*/