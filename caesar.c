#include <stdio.h> //print
#include <cs50.h> //get_string
#include <string.h> //strlen
#include <ctype.h> //isaplha
#include <stdlib.h> //atoi >> converts string to integer

int refuse(int , string s);

int main(int argc, string argv[]) //argc = # of arguments & argv[] = words received from command line
{
    if(refuse(argc, argv[1]) == 1) //test to refuse problems like more arguments, not an integer, false integer
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]); //turns string to an integer
    string plaintext = get_string("plaintext: ");


    for (int i = 0, n = strlen(plaintext); i < n; i++) //Test if will be higher than z/Z, convert and cipher
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
    return 0;
}

int refuse (string s)
{
    if (argc != 2 || key <= 0)
    {
        return 1;
    }
    for (int j = 0, n = strlen(argv[1]); j < n; j++)
    {
        if (argv[1][j] < '0' || argv[1][j] > 9)
        {
            return 1;
        }
    }
}