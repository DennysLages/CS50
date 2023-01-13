#include<stdio.h>
#include<cs50.h>

int take_coins(int coins, float change, float cent);
float take_change(float change, float cent);

int main(void)
{
    int coins = 0; //Track # of coins
    float change = get_float("Change:"); //Get amount to change

    coins = take_coins(coins, change, 0.25);
    change = take_change(change, 0.25);

    coins = take_coins(coins, change, 0.1);
    change = take_change(change, 0.1);

    coins = take_coins(coins, change, 0.05);
    change = take_change(change, 0.05);

    coins = take_coins(coins, change, 0.01);
    change = take_change(change, 0.01);

    printf("# of coins used: %i\n", coins);
}

int take_coins(int coins, float change, float cent)
{
    for (float i = change; i >= cent; i -= cent)
    {
        coins++;
    }
    printf("# of coins used: %i\n", coins);
    return coins;
}

float take_change(float change, float cent)
{
    for (float i = change; i > cent; i -= cent)
    {
        change -= cent;
    }
    printf("Remaining change: %.2f\n", change);
    return change;
}





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

/*2.56
take 0.25 , remaining > 0.25
take money divide per 0.25 , take integer

coins = integer
money = money - integer

take money divide per 0.1 , take integer*/
