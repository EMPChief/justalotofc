#include <stdio.h>

int main(){
    // tenary operator is a shortcut for if-else statement when assigning or returning a value
    // syntax: variable = (condition) ? value1 if true : value2 if false;
    int x = 10;
    int y = 20;
    int max = (x > y) ? x : y;
    printf("Maximum value is: %d\n", max);
    return 0;
}
