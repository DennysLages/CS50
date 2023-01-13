#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    long number = getlong("Card# :%li\n");

    Take number / 10, do this until >> zero
    Atribute mod 10 * 2 to a sum

    int sum = 0;
    do
    {
        int i = number % 10;
        sum = sum i * 2;
        number = number / 10;
    } while(number > 0)

    do
    {
        int i = number % 10;
        sum = sum i * 2;
        number = number / 10;
    } while(number > 0)

    printf("%i, sum");

}