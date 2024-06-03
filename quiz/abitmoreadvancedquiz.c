#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUIZ_QUESTIONS 15

void shuffle(int *array, int array_size);

// Define a struct to hold a quiz question and its answer options
typedef struct {
    char *question;
    char *answer_options[4];
    int correct_answer_index;
} QuizQuestion;

int main() {
    int user_input, user_answer;
    int user_score = 0;

    srand(time(NULL));

    // Define an array of QuizQuestion structs
QuizQuestion quiz_questions[NUM_QUIZ_QUESTIONS] = {
    {"What is the capital of France?", {"1. Paris", "2. London", "3. Berlin", "4. Rome"}, 0},
    {"What is the capital of Germany?", {"1. Paris", "2. London", "3. Berlin", "4. Rome"}, 2},
    {"What is the capital of Italy?", {"1. Paris", "2. London", "3. Berlin", "4. Rome"}, 3},
    {"What was the first browser to use JavaScript?", {"1. Internet Explorer", "2. Netscape", "3. Safari", "4. Opera"}, 1},
    {"What was the first Linux operating system?", {"1. Unix", "2. Windows", "3. Linux", "4. MacOS"}, 2},
    {"What was the first widely-used open-source database?", {"1. MySQL", "2. PostgreSQL", "3. MongoDB", "4. SQLite"}, 0},
    {"What was the first electronic database management system?", {"1. IDS", "2. IMS", "3. Oracle", "4. Ingres"}, 0},
    {"What is the name of the very first operating system?", {"1. GM-NAA I/O", "2. Windows", "3. Linux", "4. MacOS"}, 0},
    {"What is the name of the very first programming language?", {"1. Ruby", "2. Java", "3. Python", "4. C"}, 3},
    {"Which planet is known as the Red Planet?", {"1. Earth", "2. Mars", "3. Jupiter", "4. Saturn"}, 1},
    {"What is the chemical symbol for water?", {"1. O2", "2. H2O", "3. CO2", "4. NaCl"}, 1},
    {"Who wrote 'To Kill a Mockingbird'?", {"1. Harper Lee", "2. J.K. Rowling", "3. Ernest Hemingway", "4. Mark Twain"}, 0},
    {"What is the largest mammal in the world?", {"1. Elephant", "2. Blue Whale", "3. Giraffe", "4. Great White Shark"}, 1},
    {"What is the smallest prime number?", {"1. 0", "2. 1", "3. 2", "4. 3"}, 2},
    {"Which element has the atomic number 1?", {"1. Hydrogen", "2. Helium", "3. Oxygen", "4. Carbon"}, 0}
};

    // Array to hold the order of questions
    int question_order[NUM_QUIZ_QUESTIONS];
    for (int question_index = 0; question_index < NUM_QUIZ_QUESTIONS; question_index++) {
        question_order[question_index] = question_index;
    }

    // Shuffle the order of questions
    shuffle(question_order, NUM_QUIZ_QUESTIONS);

    // Welcome message
    printf("Welcome to my quiz program\n");
    printf("> Press 7 to start\n");
    printf("> Press 0 to quit\n");

    // Get user input
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

    // Iterate through each question
    for (int question_index = 0; question_index < NUM_QUIZ_QUESTIONS; question_index++) {
        int current_question_index = question_order[question_index];
        printf("%s\n", quiz_questions[current_question_index].question);
        // Display answer options
        for (int option_index = 0; option_index < 4; option_index++) {
            printf("%s\n", quiz_questions[current_question_index].answer_options[option_index]);
        }
        // Get user answer
        scanf("%d", &user_answer);
        // Check if answer is correct
        if (user_answer - 1 == quiz_questions[current_question_index].correct_answer_index) {
            printf("Correct\n");
            user_score += 1;
        } else {
            printf("Wrong\n");
        }
        // Display current score
        printf("Your score so far is %d\n", user_score);
    }

    // Display final score
    printf("Thanks for playing\n");
    printf("Your final score is %d\n", user_score);

    return 0;
}

// Function to shuffle an array
void shuffle(int *array, int array_size) {
    if (array_size > 1) {
        for (int array_index = 0; array_index < array_size - 1; array_index++) {
            int random_index = array_index + rand() / (RAND_MAX / (array_size - array_index) + 1);
            int temp_value = array[array_index];
            array[array_index] = array[random_index];
            array[random_index] = temp_value;
        }
    }
}
