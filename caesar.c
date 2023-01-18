#include <stdio.h> //print
#include <cs50.h> //get_string
#include <string.h> //strlen
#include <ctype.h> //isaplha
#include <stdlib.h> //atoi >> converts string to integer

int main(int argc, string argv[]) //argc = # of arguments & argv[] = words received from command line
{
    int key = atoi(argv[1]);
    while (argc != 2 || key <= 0)
    {
        printf("Usage: ./caesar key");
    }

    string plaintext = get_string("plaintext: ");


    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char test = plaintext[i] + key;
            if (test > 'Z')
            {
                plaintext[i] -= 'Z' - 'A' + 1;
            }
            else if (test > 'z')
            {
                plaintext[i] -= 'z' - 'a' + 1;
            }

            plaintext[i] += key;
        }
    }

    printf("ciphertext: %s\n", plaintext);
}