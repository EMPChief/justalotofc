void hello(char[], int); // Function prototype

int main()
{
    // FUNCTION PROTOTYPE
    // A function declaration without a body, appearing before main().
    // Ensures that calls to a function are made with the correct arguments.

    // IMPORTANT NOTES
    // - Many C compilers do not check for parameter matching.
    // - Missing arguments will result in unexpected behavior.
    // - A function prototype ensures the compiler flags an error if arguments are missing or mismatched.

    // ADVANTAGES
    // 1. Makes it easier to navigate a program by placing main() at the top.
    // 2. Aids in debugging by ensuring function calls are correct.
    // 3. Commonly used in header files to declare functions shared across multiple files.

    char name[] = "Bro";
    int age = 21;

    hello(name, age);

    return 0;
}

void hello(char name[], int age)
{
    printf("\nHello %s", name);
    printf("\nYou are %d years old", age);
}
