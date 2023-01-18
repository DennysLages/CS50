#include <stdio.h>  //For print
#include <cs50.h>   //For get_string
#include <string.h> //For strlen
#include <math.h>   //For round

int main(void)
{
    string text = get_string("Text:\n");
    int l = 0; //letters
    int s = 0; //sentences
    int w = 0; //words

    // Needs to count # of words (w), # of letters (l) and # of sentences (s).
    // Does not count punctuation.
    // So it needs to be inside a & z or A and Z.

    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z') // Get letters = look one by one and check if it is a valid letter until find \0.
        {
            l++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            l++;
        }

        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            s++;
        }

        if (text[i] == ' ' || text[i] == '\0') // Get words = look one by one and count++ if find "space" until find \0.
        {
            w++;
        }
    }

    float average100 = 100 / (float) w;
    int index = round(0.0588 * l * average100 - 0.296 * s * average100 - 15.8);

    if (index < -1)
    {
        printf("Before Grade 1");
    }
    else if (index > 16)
    {
        printf("Grade 16+");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade: %i\n", index);
    }

    return 0;
}