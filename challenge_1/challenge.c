#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "secret.h"

#define BUFFER_SIZE 50
#define flagsize 100

char buffer[BUFFER_SIZE];
char flag[flagsize];
char partial_key[KEY_MAX];

int win(void)
{
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }

    if (strcmp(buffer, "win\n") == 0) {
        size_t n = strlen(original_key);
        xor_hash(original_key, hash, partial_key, n);
        xor_hash(partial_key, hash, flag, n);         
        printf("Correct password! Here's your flag: %s\n", flag);
        return 1;
    }
    return 0;
}

int main(void)
{
    printf("Enter the password: ");
    if (win()) {
        return 0;
    }
    printf("Incorrect password.\n try again.\n");
    return 1;
}