#include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL)
    {
        printf("File open error\n");
        return 1;
    }

    fprintf(fp, "Hello, World!\n");
    fprintf(fp, "This is a test file.\n");
    fprintf(fp, "I love C!\n");
    fclose(fp);

    if (remove("test.txt") == 0)
    {
        printf("File removed successfully\n");
    }
    else
    {
        printf("File removal failed\n");
    }

    FILE *fp2 = fopen("testy.txt", "w+");
    if (fp2 == NULL)
    {
        printf("File open error\n");
        return 1;
    }

    fprintf(fp2, "Hello, World!\n");
    fprintf(fp2, "This is a test file.\n");
    fprintf(fp2, "I love C!\n");

    rewind(fp2);

    char buffer[100];
    size_t bytesRead = fread(buffer, sizeof(char), 100, fp2);
    if (bytesRead > 0)
    {
        printf("Read from file: \n");
        fwrite(buffer, sizeof(char), bytesRead, stdout);
    }
    else
    {
        printf("File read error\n");
    }

    fclose(fp2);
    return 0;
}
