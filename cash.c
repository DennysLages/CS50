#include<stdio.h>
#include<cs50.h>

int take.cent(cent);

int main(void)
{
    int coins = 0; //Count # of coins
    float change = get_float("Change:"); //Get amount to change

    take.cent(0.25);
    take.cent(0.1);
    take.cent(0.05);
    take.cent(0.01);

    //float change; //Calculate remaining change

    //Would work if know how to make a list
    /*coins = change / 0.25;
    change = change - coins*0.25;

    coins = change / 0.10;
    change = change - coins*0.10;

    coins = change / 0.05;
    change = change - coins*0.05;

    coins = change / 0.05;
    change = change - coins*0.01;*/

    printf("# of coins used: %i\n", coins);

    /*for (i = change; i > 0.25; i - 0.25)
    {
        coins++;
        change -= 0.25;
    }

    for (i = change; i > 0.10; i - 0.10)
    {
        count++;
        change -= 0.1;
    }*/
}

/*2.56
take 0.25 , remaining > 0.25
take money divide per 0.25 , take integer

coins = integer
money = money - integer

take money divide per 0.1 , take integer*/

int take.cent(cent)
{
    for (i = change; i > cent; i - cent)
    {
        coins++;
        change -= cent;
    }
    return coins;
}