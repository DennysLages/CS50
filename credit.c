#include<stdio.h>
#include<cs50.h>
#include<math.h>

int checksum(long card_number);

int main(void)
{
    long card_number = get_long("Card#\n");

    if (checksum(card_number) % 10 == 0)
    {
        //printf("OK\n");
        if (round(card_number / pow(10,13)) == 34 || round(card_number / pow(10,13)) == 37)
        {
            printf("AMEX\n");
        }
        else if (round (card_number / pow(10,14)) > 50 && /*50 <*/ round (card_number / pow(10,14)) < 56)
        {
            printf("MASTERCARD\n");
        }
        else if (pow(10,12) < card_number < pow(10,13) && round(card_number / pow(10,12)) == 4)
        {
            printf("VISA\n");
        }
        else if (pow(10,15) < card_number < pow(10,16) && round(card_number / pow(10,15)) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int checksum(long card_number)
{
    long number = round(card_number / 10); //Assign card_number to a test variable
    int sum = 0;

    do
    {
        if(number % 10 * 2 < 9)
        {
            sum += (number % 10) * 2;
        }
        else
        {
            sum += ((number % 10) * 2) % 10 + 1;
        }

        printf("%i\n", sum);
        number = round(number / 100);
    } while(number > 0);

    //printf("%i\n", sum);

    number = card_number; //Reassign card_number to a test variable
    do
    {
        sum += (number % 10);
        number = round(number / 100);
    } while(number > 0);

    printf("%i\n", sum);
    return sum;
}