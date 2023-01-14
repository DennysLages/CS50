#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    long card_number = get_long("Card# :%li\n");

    //Take card_number / 10, do this until >> zero
    //Atribute mod 10 * 2 to a sum

    int number = round(card_number / 10); //Assign card_number to a test variable
    int sum = 0;

    do
    {
        sum += (number % 10) * 2;
        number = round(number / 100);
    } while(number > 0)

    number = card_number; //Reassign card_number to a test variable
    do
    {
        sum += (number % 10);
        number = round(number / 100);
    } while(number > 0)

    printf("%i, sum");

}