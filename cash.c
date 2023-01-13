#include<stdio.h>
#include<cs50.h>

int take_coins(int coins, float change, float cent);
float take_change(float change, float cent);

int main(void)
{
    int coins = 0; //Track # of coins
    float change = 0; //Prepare to receive value to change
    do //Get amount to change
    {
        change = get_float("Change:");
    }
    while (change < 0);

    coins = take_coins(coins, change, 0.25);
    change = take_change(change, 0.25);

    coins = take_coins(coins, change, 0.1);
    change = take_change(change, 0.1);

    coins = take_coins(coins, change, 0.05);
    change = take_change(change, 0.05);

    coins = take_coins(coins, change, 0.01);
    change = take_change(change, 0.01);

    printf("# of coins used: %i\n", coins);
    //printf("Remaining change: %f\n", change);
}

int take_coins(int coins, float change, float cent)
{
    for (float i = change; i >= cent; i -= cent)
    {
        coins++;
    }
    //printf("# of coins used: %i\n", coins);
    return coins;
}

float take_change(float change, float cent)
{
    for (float i = change; i >= cent; i -= cent)
    {
        change -= cent;
    }
    //printf("Remaining change: %f\n", change);
    return change;
}