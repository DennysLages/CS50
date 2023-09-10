#include "helpers.h"
// #include "stdio.h"
// #include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int h = height;
    int avrg = 0;

    if(h == 0)
    {
        return;
    }

    grayscale(h-1, width, image);
    for(int w = 0; w < width; w++)
    {
        avrg = (image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3;
        image[h][w].rgbtBlue = avrg;
        image[h][w].rgbtGreen = avrg;
        image[h][w].rgbtRed = avrg;
    }

    //grayscale(h, width, image);
    // printf("%i\n", image[height-1][width-1].rgbtBlue);
    // printf("%i\n", image[height-1][width-1].rgbtGreen);
    // printf("%i\n", image[height-1][width-1].rgbtRed);
    // printf("%i\n", avrg);

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE row_reflect[width];
    int h = height;

    if(h == 0)
    {
        return;
    }

    reflect(h, width, image);
    for(int w = 0; w < width; w++)
    {
        row_reflect[w]
    }


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