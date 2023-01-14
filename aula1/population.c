#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int years = 0;
    int start;
    int end;

    do
    {
        start = get_int("Start size: \n");
    }
    while (start < 9);

    do
    {
        end = get_int("End size: \n");
    }
    while (start > end);

    for(int i = 0; start < end; i++)
    {
        start += start/3 - start/4;
        years++;
    }

    printf("Years: %i\n", years);
}