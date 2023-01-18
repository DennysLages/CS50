#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text:\n");
    int l = 0;
    int s = 0;

    // Needs to count # of words (s) and # of letters (l).
    // Does not count punctuation.
    // So it needs to be inside a & z or A and Z.

    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z') // Get letters = look one by one and check if it is a valid letter until find \0.
        {
            l++;
        }
        else if(text[i] >= 'A' && text[i] <= 'Z')
        {
            l++;
        }

        if (text[i] == ' ' || text[i] == '\0') // Get words = look one by one and count++ if find "space" until find \0.
        {
            s++;
        }
    }

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    printf("Grade: \n", index);

    return 0;
}