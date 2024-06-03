#include <stdio.h>

int main() {
    int i;
    int ans;
    int score = 0;

    printf("Welcome to my quiz program\n");

    printf("> Press 7 to start\n");
    printf("> Press 0 to quit\n");

    scanf("%d", &i);
    if (i == 7) {
        printf("Let's begin\n");
    } else if (i == 0) {
        printf("Thanks for playing\n");
        return 0;
    } else {
        printf("Invalid input\n");
        return 1;
    }

    printf("What is the capital of France?\n");
    printf("1. Paris\n");
    printf("2. London\n");
    printf("3. Berlin\n");
    printf("4. Rome\n");
    scanf("%d", &ans);
    if (ans == 1) {
        printf("Correct\n");
        score += 1;
    } else {
        printf("Wrong\n");
    }
    printf("Your score is %d\n", score);

    printf("What is the capital of Germany?\n");
    printf("1. Paris\n");
    printf("2. London\n");
    printf("3. Berlin\n");
    printf("4. Rome\n");
    scanf("%d", &ans);
    if (ans == 3) {
        printf("Correct\n");
        score += 1;
    } else {
        printf("Wrong\n");
    }
    printf("Your score is %d\n", score);

    printf("What is the capital of Italy?\n");
    printf("1. Paris\n");
    printf("2. London\n");
    printf("3. Berlin\n");
    printf("4. Rome\n");
    scanf("%d", &ans);
    if (ans == 4) {
        printf("Correct\n");
        score += 1;
    } else {
        printf("Wrong\n");
    }
    printf("Your score is %d\n", score);

    printf("What was the first browser to use JavaScript?\n");
    printf("1. Internet Explorer\n");
    printf("2. Netscape\n");
    printf("3. Safari\n");
    printf("4. Opera\n");
    scanf("%d", &ans);
    if (ans == 2) {
        printf("Correct\n");
        score += 1;
    } else {
        printf("Wrong\n");
    }
    printf("Your score is %d\n", score);

    printf("What was the first Linux operating system?\n");
    printf("1. Unix\n");
    printf("2. Windows\n");
    printf("3. Linux\n");
    printf("4. MacOS\n");
    scanf("%d", &ans);
    if (ans == 3) {
        printf("Correct\n");
        score += 1;
    } else {
        printf("Wrong\n");
    }
    printf("Your score is %d\n", score);

    printf("Thanks for playing\n");

    printf("Your final score is %d\n", score);

    return 0;
}
