#include <cs50.h> //get_string
#include <stdio.h> //printf
#include <string.h> //strlen
#include <ctype.h> //islower & isupper

// Points assigned to each letter of the alphabet
const int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_points(string player);

int main(void)
{
    //Get inputs from both players
    string p_1 = get_string("Player 1:\n");
    string p_2 = get_string("Player 2:\n");

    //Get points from both words
    int sum1 = get_points(p_1);
    int sum2 = get_points(p_2);

    if (sum1 > sum2)
    {
        printf("Player 1 wins!\n");
    }
    else if (sum2 > sum1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

//Compute and return score of each player
int get_points(string player)
{
    int position;
    int sum = 0;

    for (int i = 0, n = strlen(player); i < n; i++)
    {
        if (islower(player[i]))
        {
            position = player[i] - 'a';
            sum += points[position];
        }
        else if (isupper(player[i]))
        {
            position = player[i] - 'A';
            sum += points[position];
        }
    }
    return sum;
}

/*
1. Write table of points to an array;
2. Get from user a string ("Player 1:\n");
3. Get from user a string ("Player 2:\n");
4. Define sum1 & sum2 checking points of each char
5. Higher wins ("Player 1 or 2 wins!\n");*/