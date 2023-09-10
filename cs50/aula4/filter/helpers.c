#include "helpers.h"
#include "stdio.h"
#include "math.h"

void copying(DWORD avrg, RGBTRIPLE *rgbt);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //int h = 0;
    /*if(h > height)
    {
        return;
    }*/

    int avrg = 0;

            // int avrg = round((image[0][0].rgbtBlue + image[0][0].rgbtGreen + image[0][0].rgbtRed)) / 3; // it will colapse 255 byte of 8 bits. need a long byte, if it exists.
    for(int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            avrg = (image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3; // it will colapse 255 byte of 8 bits. need a long byte, if it exists.
            // copying(avrg, &image[h][w]);
            // copy(&avrg, &image[h][w].rgbtGreen);
            // copy(&avrg, &image[h][w].rgbtRed);
            // image[h][w].rgbtBlue = avrg;
            // image[h][w].rgbtGreen = avrg;
            // image[h][w].rgbtRed = avrg;

            //Need to change data in image.rgbt, not to be lost. Maybe use pointers somehow.
            //w++;
        }
        //h++;
    }

    //grayscale(h, width, image);
    printf("%i\n", image[height-1][width-1].rgbtBlue);
    printf("%i\n", image[height-1][width-1].rgbtGreen);
    printf("%i\n", image[height-1][width-1].rgbtRed);
    printf("%i\n", avrg);

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// void copying(DWORD avrg, RGBTRIPLE *rgbt)
// {
//     // *rgbt = *avrg;
//     *rgbt.rgbtBlue = avrg;
//     *rgbt.rgbtGreen = avrg;
//     *rgbt.rgbtRed = avrg;
// }

// int averageBYTE(BYTE a, BYTE b, BYTE c)
// {
//     avrg = 0;
//     for(int i = 0; i < strlen(BYTE); i++)
// }


// THINK ABOUT IT bf.bfType != 0x4d42