#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    int years = 0;

    do
    {
        int start = get_int("Start size: \n");
        int end = get_int("End size: \n");
    }
    while (start > end);

    do
    {
        start += start/3 - start/4;
        years++;
    }
    while (start < end);

    prinf("Years: %i\n", years);
}