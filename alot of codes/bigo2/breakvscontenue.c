#include <stdio.h>

int main() {
    // contenue - skips rest of code & forces the next iteration of the loop
    // break - exits the loop/switch/for/do/while
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (i == 5) {
            break;
        }
        printf("%d\n", i);
    }
    return 0;
}

/*
int main() {
    // contenue - skips rest of code & forces the next iteration of the loop
    // break - exits the loop/switch/for/do/while
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (i == 5) {
            continue;
        }
        printf("%d\n", i);
    }
    return 0;
}
*/