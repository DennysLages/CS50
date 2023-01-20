#include <stdio.h> //print
#include <cs50.h> //get_string
#include <string.h> //strlen
#include <ctype.h> //isaplha isupper islower
#include <stdlib.h> //atoi >> converts string to integer

int main(int argc, string argv[])
{
    //Test Key.1 Check # of argc
    if (argc !=2)
    {
        printf("Usage: ./substitution KEY");
        return 1;
    }

    int LEN_KEY = strlen(argv[1]);

    if (LEN_KEY != 26)
    {
        printf("Usage: ./substitution KEY");
        return 1;
    }

    /*//Test2. Check key size and if only alpha
    int n = strlen(argc[1]);*/

    //Test Key.2 & 3 Check if only alpha & non repeatable letters
    char key[LEN_KEY];

    for (int i = 0; i < LEN_KEY; i++)
    {
        if (!isaplha(argv[1][i]))
        {
            printf("only use alpha key");
            return 1;
        }

        for (int j = i + 1; j < LEN_KEY; j++)
        {
            if (key[i] == key[j])
            {
                printf("Do not repeat letters");
                return 1;
            }
        }
    }

    //4. Get key by list of positions
    for (int i = 0; i < LEN_KEY;i++)
    {
        if (isaplha(s[i]))
        {
            if (islower(s[i]))
            {
                key[i] = s[i] - 'a';
            }
            else if (isupper(s[j]))
            {
                key[i] = s[i] - 'A';
            }
        }
    }

    //5.
}


    //const int LEN_KEY = validate_arg(argc, argv[1])

1. Validate Key
    1.1 Only 2 CLArg
    1.2 Only Alpha chars
    1.3 Non Repeatable letters
2. Get Plaintext
    2.1 Resume each letter to a position (a or A)
3. Encipher
    3.1 Get each letter + key (position)
4. Print ciphetext