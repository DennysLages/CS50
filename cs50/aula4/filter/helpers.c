#include "helpers.h"

copy(int *a, int *b)

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //int h = 0;
    /*if(h > height)
    {
        return;
    }*/

    for(int h = 0, h < height, h++)
    {
        for(int w = 0, w < width, w++)
        {
            int avrg = (image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3;
            copy(&avrg, &image[h][w].rgbtBlue);
            // image[h][w].rgbtBlue = avrg;
            // image[h][w].rgbtGreen = avrg;
            // image[h][w].rgbtRed = avrg;

            //Need to change data in image.rgbt, not to be lost. Maybe use pointers somehow.
            //w++;
        }
        //h++;
    }

    //grayscale(h, width, image);

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

void copy(int *avrg, int *rgbt)
{
    tmp = *a;
    *a = *b;
    *b = tmp;
}
