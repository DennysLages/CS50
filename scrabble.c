#include <cs50.h> //get_string
#include <stdio.h> //printf

const int points = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_points(string player);

int main(void)
{
    string p_1 = get_string("Player 1:\n");
    string p_2 = get_string("Player 2:\n");

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
        printf("That is a draw!\n");
    }
}

int get_points(string player)
{
    for (int i = 0, n = strlen(p_1); i++)
    {
        if (islower(player))
        {
            position = player[i] - 'a';
            sum = points[position];
        }
        else if (isupper(player))
        {
            position = player[i] - 'A';
            sum = points[position];
        }
    }
    return sum;
}

1. Write table of points to an array;
2. Get from user a string ("Player 1:\n");
3. Get from user a string ("Player 2:\n");
4. Define sum1 & sum2 checking points of each char
5. Higher wins ("Player 1 or 2 wins!\n");