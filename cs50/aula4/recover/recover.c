#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //Necessary for uint8_t and creation of BYTE

typedef uint8_t BYTE;
const int BLOCK = 512;

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) //!file
    {
        printf("Not possible to open %s.\n", argv[1]);
        return 1;
    }

    //fread(file, 512, )
    buffer[512];

    fread(buffer, 512, 255, file)
}