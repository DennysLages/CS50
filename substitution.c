#include <stdio.h> //print
#include <cs50.h> //get_string
#include <string.h> //strlen
#include <ctype.h> //isaplha isupper islower
#include <stdlib.h> //atoi >> converts string to integer

int main(int argc, string argv[])
{
    //Key 1. Check # of argc
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    const int LEN_KEY = strlen(argv[1]);

    if (LEN_KEY != 26)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    //Key 2 & 3. Check if only alpha & non repeatable letters
    char key[LEN_KEY];

    for (int i = 0; i < LEN_KEY; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("only use alpha key\n");
            return 1;
        }

        for (int j = i + 1; j < LEN_KEY; j++)
        {
            if (key[i] == key[j])
            {
                printf("Do not repeat letters\n");
                return 1;
            }
        }
    }

    //Key 4. Get key by list of positions
    for (int i = 0; i < LEN_KEY;i++)
    {
        if (isalpha(argv[1][i]))
        {
            if (islower(argv[1][i]))
            {
                key[i] = argv[1][i] - 'a';
            }
            else if (isupper(argv[1][i]))
            {
                key[i] = argv[1][i] - 'A';
            }
        }
    }

    //Plaintext 5. Get text, resume each letter(alpha) to a position & encypher back
    string plaintext = get_string("plaintext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++) //Check caps and z/Z end. Convert and cipher.
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int position = plaintext[i] - 'A';
                plaintext[i] = 'A' + key[position];
            }
            else if (islower(plaintext[i]))
            {
                int position = plaintext[i] - 'a';
                plaintext[i] = 'a' + key[position];
            }
        }
    }

    // Print final result
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

/*
1. Validate Key
    1.1 Only 2 CLArg
    1.2 Only Alpha chars
    1.3 Non Repeatable letters
2. Get Plaintext
    2.1 Resume each letter to a position (a or A)
3. Encipher
    3.1 Get each letter + key (position)
4. Print ciphetext*/