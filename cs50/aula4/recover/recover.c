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
    // Buffer / Destination / Destination_Name / Track#
    //Creation of buffer of size 512 bytes
    BYTE buffer[BLOCK];

    // Creation of Destination file
    FILE *img;

    // String for Destination Name Creation
    char *name_img = malloc(8); //###.jpg\0

    // Creation of variable to track # of images
    int i = 0;


    // [2. Iterations / Hard coding]
    //While not end of file, do
    //Read all BLOCKS of 512 bytes each
    while (fread(&buffer, 1, BLOCK, file))
    {
        // Check first bytes if it is a jpeg and start printing
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Function to create a String that will be used as name
            sprintf(name_img, "%03i.jpg", i);

            //Create a file img with name name_img and Write a file (image) for that 1 block
            img = fopen(name_img, "w");
            fwrite(buffer, 1, BLOCK, img);
            i++;
        }

    buffer[512];

    fread(buffer, 512, 255, file)
}