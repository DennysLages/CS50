#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen("card.raw", "r");
    if (file == NULL)
    {
        return 1;
    }

    fread(file, 512, )

}