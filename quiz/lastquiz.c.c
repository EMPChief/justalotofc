#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ANSWER_OPTIONS 4

// Definerer en struktur for å holde et quizspørsmål og dens svaralternativer
typedef struct
{
    char *question;
    char *answer_options[NUM_ANSWER_OPTIONS];
    int correct_answer_index;
} QuizQuestion;

void shuffle(int *array, int array_size);
void shuffle_options(char *options[], int correct_answer_index, int *new_correct_index);
void display_question(QuizQuestion question, int *new_correct_index);
int get_user_input();
void show_score(int score, int total_questions);
void initialize_quiz_order(int *order, int num_questions);

int main()
{
    srand(time(NULL));

    // Definerer en array av QuizQuestion-strukturer
    QuizQuestion quiz_questions[] = {
        {"What is the capital of France?", {"Paris", "London", "Berlin", "Rome"}, 0},
        {"What is the capital of Germany?", {"Paris", "London", "Berlin", "Rome"}, 2},
        {"What is the capital of Italy?", {"Paris", "London", "Berlin", "Rome"}, 3},
        {"What was the first browser to use JavaScript?", {"Internet Explorer", "Netscape", "Safari", "Opera"}, 1},
        {"What was the first Linux operating system?", {"Unix", "Windows", "Linux", "MacOS"}, 2},
        {"What was the first widely-used open-source database?", {"MySQL", "PostgreSQL", "MongoDB", "SQLite"}, 0},
        {"What was the first electronic database management system?", {"IDS", "IMS", "Oracle", "Ingres"}, 0},
        {"What is the name of the very first operating system?", {"GM-NAA I/O", "Windows", "Linux", "MacOS"}, 0},
        {"What is the name of the very first programming language?", {"C", "Java", "Python", "Plankalkul"}, 3},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 1},
        {"What is the chemical symbol for water?", {"O2", "H2O", "CO2", "NaCl"}, 1},
        {"Who wrote 'To Kill a Mockingbird'?", {"Harper Lee", "J.K. Rowling", "Ernest Hemingway", "Mark Twain"}, 0},
        {"What is the largest mammal in the world?", {"Elephant", "Blue Whale", "Giraffe", "Great White Shark"}, 1},
        {"What is the smallest prime number?", {"0", "1", "2", "3"}, 2},
        {"Which element has the atomic number 1?", {"Hydrogen", "Helium", "Oxygen", "Carbon"}, 0}};

    // Sjekker hvor mange spørsmål som er i arrayen
    int num_quiz_questions = sizeof(quiz_questions) / sizeof(quiz_questions[0]);
    int question_order[num_quiz_questions];

    // Initialiserer rekkefølgen til quizspørsmålene
    initialize_quiz_order(question_order, num_quiz_questions);
    // Blander rekkefølgen til quizspørsmålene

    shuffle(question_order, num_quiz_questions);
    // Velkommelding til quizen
    printf("Welcome to my quiz program\n");
    printf("> Press 7 to start\n");
    printf("> Press 0 to quit\n");

    // Tar brukerens inndata
    int user_input = get_user_input();
    if (user_input == 0)
    {
        printf("Thanks for playing\n");
        return 0;
    }
    else if (user_input != 7)
    {
        printf("Invalid input\n");
        return 1;
    }

    int user_score = 0;
    // for loop så går gjennom hvert quizspørsmål
    for (int question_index = 0; question_index < num_quiz_questions; question_index++)
    {
        int current_question_index = question_order[question_index];
        int new_correct_index;
        // Viser spørsmålet og svaralternativene
        display_question(quiz_questions[current_question_index], &new_correct_index);

        char user_answer;
        printf("Your answer (A, B, C, D): ");
        scanf(" %c", &user_answer);

        int user_answer_index = user_answer - 'A';
        if (user_answer_index < 0 || user_answer_index >= NUM_ANSWER_OPTIONS)
        {
            printf("Invalid answer. Please enter a letter between A and D.\n");
            continue;
        }

        // Sjekker om svaret er riktig og øker brukerens poengsum
        if (user_answer_index == new_correct_index)
        {
            printf("Correct! Your answer is right: %s\n", quiz_questions[current_question_index].answer_options[user_answer_index]);
            user_score += 1;
        }
        else
        {
            printf("Wrong. The correct answer is: %s\n", quiz_questions[current_question_index].answer_options[new_correct_index]);
        }
        printf("Your score so far is %d\n", user_score);
    }
    // Viser brukerens endelige poengsum
    show_score(user_score, num_quiz_questions);
    return 0;
}

// Funksjon for å blande rekkefølgen til et array
void shuffle(int *array, int array_size)
{
    if (array_size > 1)
    {
        for (int array_index = 0; array_index < array_size - 1; array_index++)
        {
            int random_index = array_index + rand() / (RAND_MAX / (array_size - array_index) + 1);
            int temp_value = array[array_index];
            array[array_index] = array[random_index];
            array[random_index] = temp_value;
        }
    }
}

// Funksjon for å blande rekkefølgen på svaralternativene
void shuffle_options(char *options[], int correct_answer_index, int *new_correct_index)
{
    char *temp_options[NUM_ANSWER_OPTIONS];
    int order[NUM_ANSWER_OPTIONS];
    for (int index = 0; index < NUM_ANSWER_OPTIONS; index++)
    {
        order[index] = index;
    }
    shuffle(order, NUM_ANSWER_OPTIONS);
    for (int index = 0; index < NUM_ANSWER_OPTIONS; index++)
    {
        temp_options[index] = options[order[index]];
        if (order[index] == correct_answer_index)
        {
            *new_correct_index = index;
        }
    }
    for (int index = 0; index < NUM_ANSWER_OPTIONS; index++)
    {
        options[index] = temp_options[index];
    }
}

// Funksjon for å vise et spørsmål og dets svaralternativer
void display_question(QuizQuestion question, int *new_correct_index)
{
    char *shuffled_options[NUM_ANSWER_OPTIONS];
    for (int index = 0; index < NUM_ANSWER_OPTIONS; index++)
    {
        shuffled_options[index] = question.answer_options[index];
    }

    shuffle_options(shuffled_options, question.correct_answer_index, new_correct_index);

    printf("%s\n", question.question);
    for (int option_index = 0; option_index < NUM_ANSWER_OPTIONS; option_index++)
    {
        printf("%c. %s\n", 'A' + option_index, shuffled_options[option_index]);
    }
}

// Funksjon for å hente brukerens inndata
int get_user_input()
{
    int input;
    scanf("%d", &input);
    return input;
}

// Funksjon for å vise brukerens poengsum
void show_score(int score, int total_questions)
{
    printf("Thanks for playing\n");
    printf("Your final score is %d out of %d (%.2f%%)\n", score, total_questions, (score / (float)total_questions) * 100);
}

// Funksjon for å initialisere rekkefølgen til quizspørsmålene
void initialize_quiz_order(int *order, int num_questions)
{
    for (int index = 0; index < num_questions; index++)
    {
        order[index] = index;
    }
}
