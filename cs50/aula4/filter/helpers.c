#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int h = 0;
    int w = 0;
    /*if(h > height)
    {
        return;
    }*/

    while(h < height)
    {
        while(w < width)
        {
            int avrg = (image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3;
            *image[h][w].rgbtBlue = avrg;
            *image[h][w].rgbtGreen = avrg;
            *image[h][w].rgbtRed = avrg;
            w++;
        }
        h++;
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
