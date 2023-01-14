#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    long card_number = get_long("Card#\n");

    //Take card_number / 10, do this until >> zero
    //Atribute mod 10 * 2 to a sum

    long number = round(card_number / 10); //Assign card_number to a test variable
    int sum = 0;

    //number = number % 10;
    //printf("%li\n", number);

    do
    {
        if(number % 10 * 2 < 9)
        {
            sum += (number % 10) * 2;
        }
        else
        {
            sum += ((number % 10) * 2) % 10 + 2;
        }

        printf("%i\n", sum);
        number = round(number / 100);
    } while(number > 0);

    printf("%i\n", sum);

    number = card_number; //Reassign card_number to a test variable
    do
    {
        sum += (number % 10);
        number = round(number / 100);
    } while(number > 0);

    printf("%i\n", sum);

}