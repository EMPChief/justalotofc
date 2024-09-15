/* test.c */
#include "arcfour.h"
#define F fflush(stdout)

int main(void);

int main()
{
    Arcfour *rc4;
    int16 size_key, size_plaintext;
    char *key, *plaintext, *ciphertext, *decryptedtext;

    key = "computerisavirus";
    size_key = strlen(key);
    plaintext = "Crush your enemy completely. If you leave even one ember smoldering, it will eventually ignite. You can’t afford to be lenient.";
    size_plaintext = strlen(plaintext);
    printf("Starting encrypting\n");

    rc4 = rc4init(key, size_key);
    printf("Finished encrypting\n");

    printf("Plaintext: %s\n", plaintext);
    encryptedtext = rc4encrypt(rc4, plaintext, size_plaintext);

    

}