/* arcfour.h */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define rc4decrypt(a, b) rc4encrypt(a, b)

struct s_arcfour {
    
}

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

Arcfour *rc4init(int8*, int16);
int8 rc4byte(void);
int8 *rc4encrypt(int8*, int32);