#include <stdio.h> //print
#include <cs50.h> //get_string
#include <string.h> //strlen
#include <ctype.h> //isaplha

int main(int argc, string argv[])
{
    while (argc <= 0)
    {
        printf("Usage: ./caesar key");
    }

    string plaintext = get_string("plaintext: ");


    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char test = plaintext[i] + argc;
            if (test > 'Z')
            {
                plaintext[i] -= 'A';
            }
            plaintext[i] += argc;
        }
    }

    printf("ciphertext: %s\n", plaintext);
}