#include<stdio.h>
#include<cs50.h>

int, float take_cent(int coins, float change, float cent);

int main(void)
{
    int coins = 0; //Count # of coins
    float change = get_float("Change:"); //Get amount to change

    coins = take_cent(coins, change, 0.25);
    coins = take_cent(coins, change, 0.1);
    coins = take_cent(coins, change, 0.05);
    coins = take_cent(coins, change, 0.01);

    printf("# of coins used: %i\n", coins);
}

int, float take_cent(int coins, float change, float cent)
{
    for (float i = change; i > cent; i -= cent)
    {
        coins++;
        change -= cent;
        printf("# of coins used: %i\n", coins);
    }
    return coins;
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
