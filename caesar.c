#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    string plaintext = get_string("plaintext: ");

    for(int i = 0, n = strlen(plaintext); i < n; i++)
    {
        plaintext[i] += argc;
    }

    printf("ciphertext: %s", plaintext);
}