#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");
    printf("What's your name?\n");
    string name = get_string("What is your name");
    printf("Hi, %s. Nice to meet you!\n", name);
    return 0;
}
