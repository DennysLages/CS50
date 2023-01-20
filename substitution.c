#include <stdio.h> //print
#include <cs50.h> //get_string
#include <string.h> //strlen
#include <ctype.h> //isaplha isupper islower
#include <stdlib.h> //atoi >> converts string to integer

int validate_key(int size, string s[]);

int main(int argc, string argv[]) //argc = # of arguments & argv[] = words received from command line
{
    char key = validate_key(argc, argv[1]);
    /*if (key == 1) //test to refuse problems like more arguments, not an integer, false integer
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }*/

    const int LEN_KEY = strlen(key);

    string plaintext = get_string("plaintext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++) //Check caps and z/Z end. Convert and cipher.
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int position = plaintext[i] - 'A';
                plaintext[i] = 'A' + key[position];

                /*for (int j = 0; j < LEN_KEY ; j++)
                {
                   plaintext[j] = argv[1][j];
                }
                //plaintext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;*/
            }
            else if (islower(plaintext[i]))
            {
                int position = plaintext[i] - 'a';
                plaintext[i] = 'a' + key[position];

                /*for (int j = 0; j < n ; j++)
                {
                plaintext[j] = argv[1][j];
                }
                //plaintext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;*/
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}

//if argv[1] don`t exist, there will be no Aux Function validate_key
int validate_key(int size, string s)
{
    //Test wrong number of CLArg, and size of key (argv(1))
    if (size != 2 || strlen(s[1]) != 26)
    {
        return 1;
    }

    //Prepare to organize key by position
    char key[strlen(s[1])];

    for (int j = 0, n = strlen(s); j < n; j++) //size = argc, s = argv[1] to test non integer key
    {
        if (!isaplha(s[j]))
        {
            return 1;
        }

        if (islower(s[j]))
        {
            key[j] = s[j] - 'a';
        }
        else if (isupper(s[j]))
        {
            key[j] = s[j] - 'A';
        }

    }

    //Check for repeated letters

    //int key = atoi(s); //turns string to an integer*/

    return key;
}


1. Validate Key
    1.1 Only 2 CLArg
    1.2 Only Alpha chars
    1.3 Non Repeatable letters
2. Get Plaintext
    2.1 Resume each letter to a position (a or A)
3. Encipher
    3.1 Get each letter + key (position)
4. Print ciphetext