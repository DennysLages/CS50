#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do //Get height between 1 & 8 from user
    {
        height = get_int("Height:\n");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++) //Creating rows from height informed
    {
        for (int j = height; j > 0; j--) //Creating row lenght (Columns)
        {
            if (j > i + 1) //Spliting sides of a line (row)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        printf("  "); //Split Piramids

        //Starting second piramid before going next line

        for (int j = 0; j < height; j++) //Creating row lenght (Columns)
        {
            if (j < i + 1) //Spliting sides of a line (row)
            {
                printf("#");
            }
        }

        printf("\n"); // Closing first line (loop i)

    }
}

