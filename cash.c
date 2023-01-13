#include<stdio.h>
#include<cs50.h>

int take_coins(int coins, float change, float cent);
int take_change(float change, float cent);

int main(void)
{
    int coins = 0; //Track # of coins
    float money = 0; //Prepare to receive positive value to change
    int change = 0;
    do //Get amount to change
    {
        money = get_float("Change:");
    }
    while (money < 0);

    change = money * 100;

    coins = take_coins(coins, change, 25);
    change = take_change(change, 25);

    coins = take_coins(coins, change, 10);
    change = take_change(change, 10);

    coins = take_coins(coins, change, 5);
    change = take_change(change, 5);

    coins = take_coins(coins, change, 1);
    change = take_change(change, 1);

    printf("%i\n", coins);
    //printf("# of coins used: %i\n", coins);
    //printf("Remaining change: %f\n", change);
}

//Calculate # of coins
int take_coins(int coins, float change, float cent)
{
    for (float i = change; i >= cent; i -= cent)
    {
        coins++;
    }
    //printf("# of coins used: %i\n", coins);
    return coins;
}

//Calculate remaining change
int take_change(float change, float cent)
{
    for (float i = change; i >= cent; i -= cent)
    {
        change -= cent;
    }
    //printf("Remaining change: %f\n", change);
    return change;
}