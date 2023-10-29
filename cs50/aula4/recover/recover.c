#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //Necessary for uint8_t and creation of BYTE

typedef uint8_t BYTE;
const int BLOCK = 512;

int main(int argc, char *argv[])
{
    // [0. Check]
    // Check number of arguments and return if not 2
    if (argc != 2)
    {
        //printf("Use: ./recover card.raw");
        return 2;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) //!file
    {
        printf("Not possible to open %s.\n", argv[1]);
        return 1;
    }

    // [1. Variable Creation]
    //Creation of buffer of size 512 bytes
    BYTE buffer[BLOCK];

    // Creation of Destination file
    FILE *img;

    // Creation of variable to track # of images
    int i = 0;


    // [2. Iterations / Hard coding]
    //While not end of file, do
    //Read all BLOCKS of 512 bytes each
    while(fread(buffer, BLOCK, 255, file))
    {
        // Check first bytes if it is a jpeg and start printing
        if ( buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", 2);
        }
    }

    //fread(file, 512, )
    buffer[512];

    fread(buffer, 512, 255, file)
}