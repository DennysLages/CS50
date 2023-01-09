#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50

int main(void)
{
    string name = get_string("Qual é o seu nome? \n");
    printf("hello, world!\n");
    printf("Olá, %s \n", name);
}