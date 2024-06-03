#include <stdio.h>

int main(){

    // switch = A more efficient alternative to using many "else if" statements allows a value to be tested for equality against many cases

    // declare and initialize variable
    char grade;

    // get user input
    printf("Enter your grade: ");
    scanf("%c", &grade);

    switch(grade){
        case 'A':
            printf("Excellent!\n\"Strive not to be a success, but rather to be of value.\" - Albert Einstein\n");
            break;
        case 'B':
            printf("Well done!\n\"The only way to do great work is to love what you do.\" - Steve Jobs\n");
            break;
        case 'C':
            printf("You passed!\n\"Success is not final, failure is not fatal: It is the courage to continue that counts.\" - Winston Churchill\n");
            break;
        case 'D':
            printf("Better try again!\n\"Success is not in what you have, but who you are.\" - Bo Bennett\n");
            break;
        case 'F':
            printf("Failed!\n\"Failure is simply the opportunity to begin again, this time more intelligently.\" - Henry Ford\n");
            break;
        default:
            printf("Invalid grade!\n");
    }

    return 0;
}
