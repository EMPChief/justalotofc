#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strset(char *str, char ch);
void strnset(char *str, char ch, size_t n);
void strrev(char *str);
int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t n);

int main() {

    char string1[100] = "Bjorn";
    char string2[] = "Prog";

    // Converts string1 to lowercase
    for(int i = 0; string1[i]; i++) {
        string1[i] = tolower(string1[i]);
    }
    printf("Lowercase string1: %s\n", string1);

    // Converts string1 to uppercase
    for(int i = 0; string1[i]; i++) {
        string1[i] = toupper(string1[i]);
    }
    printf("Uppercase string1: %s\n", string1);

    // Appends string2 to the end of string1
    strcat(string1, string2);
    printf("Concatenated string: %s\n", string1);

    // Appends 1 character from string2 to string1
    strncat(string1, string2, 1);
    printf("Concatenated with 1 char from string2: %s\n", string1);

    // Copies string2 to string1
    strcpy(string1, string2);
    printf("Copied string2 to string1: %s\n", string1);

    // Copies 2 characters from string2 to string1
    strncpy(string1, string2, 2);
    string1[2] = '\0';  // Adding null terminator to make it a valid string
    printf("Copied 2 characters from string2: %s\n", string1);

    // Sets all characters of string1 to '?'
    strset(string1, '?');
    printf("All characters set to ?: %s\n", string1);

    // Sets first 1 character of string1 to 'x'
    strnset(string1, 'x', 1);
    printf("First character set to x: %s\n", string1);

    // Reverse string1
    strcpy(string1, "Code");  // Reset string1 to "Code" for reversing
    strrev(string1);
    printf("Reversed string1: %s\n", string1);

    // Get length of string1
    int len = strlen(string1);
    printf("Length of string1: %d\n", len);

    // Compare string1 and string2
    int cmpResult = strcmp(string1, string2);
    if(cmpResult == 0) {
        printf("string1 and string2 are the same.\n");
    } else {
        printf("string1 and string2 are not the same.\n");
    }

    // Compare first character of string1 and string2
    cmpResult = strncmp(string1, string2, 1);
    if(cmpResult == 0) {
        printf("First character of string1 and string2 are the same.\n");
    } else {
        printf("First character of string1 and string2 are not the same.\n");
    }

    // Compare string1 and string2 (ignore case)
    cmpResult = strcasecmp(string1, string2);
    if(cmpResult == 0) {
        printf("string1 and string2 are the same (ignore case).\n");
    } else {
        printf("string1 and string2 are not the same (ignore case).\n");
    }

    // Compare first character of string1 and string2 (ignore case)
    cmpResult = strncasecmp(string1, string2, 1);
    if(cmpResult == 0) {
        printf("First character of string1 and string2 are the same (ignore case).\n");
    } else {
        printf("First character of string1 and string2 are not the same (ignore case).\n");
    }

    return 0;
}
// Custom implementation of strset
void strset(char *str, char ch) {
    while(*str) {
        *str++ = ch;
    }
}

// Custom implementation of strnset
void strnset(char *str, char ch, size_t n) {
    for(size_t i = 0; i < n && str[i]; i++) {
        str[i] = ch;
    }
}

// Custom implementation of strrev
void strrev(char *str) {
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Custom implementation of strcasecmp
int strcasecmp(const char *s1, const char *s2) {
    while (*s1 && (tolower((unsigned char)*s1) == tolower((unsigned char)*s2))) {
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

// Custom implementation of strncasecmp
int strncasecmp(const char *s1, const char *s2, size_t n) {
    if (n == 0) return 0;
    while (n-- != 0 && *s1 && (tolower((unsigned char)*s1) == tolower((unsigned char)*s2))) {
        s1++;
        s2++;
    }
    if (n == (size_t)-1) return 0;
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}