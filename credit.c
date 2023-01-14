#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    long card_number = getlong("Card# :%li\n");

    //Take card_number / 10, do this until >> zero
    //Atribute mod 10 * 2 to a sum

    long number = card_number; //Assign card_number to a test variable
    int sum = 0;
    do
    {
        int i = number % 10;
        sum = sum i * 2;
        number = number / 10;
    } while(number > 0)

    number = card_number; //Reassign card_number to a test variable
    do
    {
        int i = number % 10;
        sum = sum i * 2;
        number = number / 10;
    } while(number > 0)

    printf("%i, sum");

}