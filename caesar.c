#include <stdio.h> //print
#include <cs50.h> //get_string
#include <string.h> //strlen
#include <ctype.h> //isaplha

int main(int argc, string argv[]) //argc = # of arguments & argv[] = words received from command line
{
    while (argv[1] <= 0)
    {
        printf("Usage: ./caesar key");
    }

    string plaintext = get_string("plaintext: ");


    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char test = plaintext[i] + argv[1];
            if (test > 'Z')
            {
                plaintext[i] -= 'Z' - 'A' - 1;
            }
            else if (test > 'z')
            {
                plaintext[i] -= 'z' - 'a' - 1;
            }

            plaintext[i] += argv[1];
        }
    }

    printf("ciphertext: %s\n", plaintext);
}