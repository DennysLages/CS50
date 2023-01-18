#include <stdio.h>

int main(int argc)
{
    plaintext = get_string("plaintext: ");

    for(int i = 0, n = strgen(plaintext); i < n, i++)
    {
        plaintext[i] += argc;
    }

    printf("ciphertext: %s", plaintext);
}