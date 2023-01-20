#include <stdio.h> //print
#include <cs50.h> //get_string
#include <string.h> //strlen
#include <ctype.h> //isaplha isupper islower
#include <stdlib.h> //atoi >> converts string to integer

int refuse(int size, string s);

int main(int argc, string argv[]) //argc = # of arguments & argv[] = words received from command line
{
    int key = refuse(argc, argv[1]);
    if (key == -1) //test to refuse problems like more arguments, not an integer, false integer
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++) //Check caps and z/Z end. Convert and cipher.
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                For (int j = 0; argv[1][j] != \0; j++)
                {
                   Plaintext[j] = argv[1][j];
                }
                //plaintext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
            }
            else if (islower(plaintext[i]))
            {
                For (int j = 0; argv[1][j] != \0; j++)
                {
                Plaintext[j] = argv[1][j];
                }
                //plaintext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}

int refuse(int size, string s) //if argv[1] don`t exist, there will be no refuse()
{
    if (size != 2) //Test wrong number of CLArg
    {
        return -1;
    }

    for (int j = 0, n = strlen(s); j < n; j++) //size = argc, s = argv[1] to test non integer key
    {
        if (s[j] < '0' || s[j] > '9')
        {
            return -1;
        }
    }

    int key = atoi(s); //turns string to an integer

    return key;
}