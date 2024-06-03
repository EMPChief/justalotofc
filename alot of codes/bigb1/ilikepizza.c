#include <stdio.h>

int main() {
    // I like pizza <- single line comment
    /* 
    I like pizza!! <- multi line comment
    */
    printf("I like pizza!!\n"); // single line output
    printf("I really like pizza!!\n"); // single line output
    printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n"); // tabbed output
    printf("\"The only way to do great work is to love what you do.\" - Steve Jobs\n"); // quoted output with escape sequences
    printf("\'Life is what happens when you're busy making other plans.\' - John Lennon\n"); // quoted output with single escape sequences
    printf("\\Change your thoughts and you change your world.\\ - Norman Vincent Peale\n"); // quoted output with multiple escape sequences

    return 0;
}
