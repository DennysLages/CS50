#include <stdio.h> //print
#include <cs50.h> //get_string
#include <string.h> //strlen
#include <ctype.h> //isaplha
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

    for (int i = 0, n = strlen(plaintext); i < n; i++) //Test if will be higher than z/Z, convert and cipher
    {
        if (isalpha(plaintext[i]))
        {
            plaintext[i] = 'A' + (plaintext[i] - 'A' + key) %26;

            /*A = 100     A = 100   Z = 126
            +2          +28         +28 >> 154 >> 102
            C = 102     ?? = A + key = 128 >> A + key%26 = A + 2;*/

            /*char test = plaintext[i] + key;
            if (test > 'Z')
            {
                plaintext[i] -= 'Z' - 'A' + 1;
            }
            else if (test > 'z')
            {
                plaintext[i] -= 'z' - 'a' + 1;
            }

            plaintext[i] += key;*/
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}

int refuse (int size, string s)
{
    for (int j = 0, n = strlen(s); j < n; j++) //size = argc, s = argv[1] to test non integer key
    {
        if (s[j] < '0' || s[j] > '9')
        {
            return -1;
        }
    }

    int key = atoi(s); //turns string to an integer

    if (size != 2 || key <= 0) //Test wrong number of CLArg and negative keys
    {
        return -1;
    }

    return key;
}

//even correct CLArg are returning as wrong