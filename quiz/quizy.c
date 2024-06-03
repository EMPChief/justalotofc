#include <stdio.h>

int main() {
    int user_input, user_answer;
    int user_score = 0;

    char *quiz_questions[] = {
        "What is the capital of France?",
        "What is the capital of Germany?",
        "What is the capital of Italy?",
        "What was the first browser to use JavaScript?",
        "What was the first Linux operating system?",
        "What is the name of the first operating system?"
    };

    char *answer_options[][5] = {
        {"1. Paris", "2. London", "3. Berlin", "4. Rome"},
        {"1. Paris", "2. London", "3. Berlin", "4. Rome"},
        {"1. Paris", "2. London", "3. Berlin", "4. Rome"},
        {"1. Internet Explorer", "2. Netscape", "3. Safari", "4. Opera"},
        {"1. Unix", "2. Windows", "3. Linux", "4. MacOS"},
        {"1. MS-DOS", "2. Windows", "3. Linux", "4. MacOS"}
    };

    int correct_answers[] = {1, 3, 4, 2, 1};

    printf("Welcome to my quiz program\n");
    printf("> Press 7 to start\n");
    printf("> Press 0 to quit\n");

    scanf("%d", &user_input);
    if (user_input == 7) {
        printf("Let's begin\n");
    } else if (user_input == 0) {
        printf("Thanks for playing\n");
        return 0;
    } else {
        printf("Invalid input\n");
        return 1;
    }

    for (int question_index = 0; question_index < 5; question_index++) {
        printf("%s\n", quiz_questions[question_index]);
        for (int option_index = 0; option_index < 4; option_index++) {
            printf("%s\n", answer_options[question_index][option_index]);
        }
        scanf("%d", &user_answer);
        if (user_answer == correct_answers[question_index]) {
            printf("Correct\n");
            user_score += 1;
        } else {
            printf("Wrong\n");
        }
        printf("Your score is %d\n", user_score);
    }

    printf("Thanks for playing\n");
    printf("Your final score is %d\n", user_score);

    return 0;
}
