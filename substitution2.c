#include <stdio.h> //print
#include <cs50.h> //get_string
#include <string.h> //strlen
#include <ctype.h> //isaplha isupper islower
#include <stdlib.h> //atoi >> converts string to integer

int main(int argc, string argv[])
{
    //Test 1. Check # of argc
    if (argc !=2)
    {
        return 1;
    }

    //Test2. 

    const int LEN_KEY = validate_arg(argc, argv[1])

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