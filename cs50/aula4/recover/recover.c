#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //Necessary for uint8_t and creation of BYTE

typedef uint8_t BYTE;
const int BLOCK = 512;

int main(int argc, char *argv[])
{
    // Check number of arguments and return if not 2
    if (argc != 2)
    {
        //printf("Use: only name of file to recovery");
        return 2;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) //!file
    {
        printf("Not possible to open %s.\n", argv[1]);
        return 1;
    }

    // Read first three bytes
    BYTE buffer[BLOCK];
    fread(buffer, BLOCK, 3, file);

    // Check first three bytes
    if ( bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {

    }
    //fread(file, 512, )
    buffer[512];

    fread(buffer, 512, 255, file)
}