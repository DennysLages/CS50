#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int count = 0; //Count # of coins
    float total.change = get_float("Change:"); //Get amount to change
    //float change; //Calculate remaining change

    for (i = total.change; i > 0.25; i - 0.25)
    {
        count++;
    }
    for (i = total.change - count*0.25; i > 0.10; i - 0.10)
    {
        count++;
    }
}