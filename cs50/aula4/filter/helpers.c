#include "helpers.h"
// #include "stdio.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int h = height;
    float avrg = 0;

    if (h < 0) //End case
    {
        return;
    }

    grayscale(h-1, width, image); // Do the grayscale for only 1 row, and repeat to the next.

    for (int w = 0; w < width; w++)
    {
        avrg = round(((float)image[h][w].rgbtBlue + (float)image[h][w].rgbtGreen + (float)image[h][w].rgbtRed) / 3);; //Average of each RGBTRIPLE and assign to all bytes (BGR) + Casting

        image[h][w].rgbtBlue = (int) avrg;
        image[h][w].rgbtGreen = (int) avrg;
        image[h][w].rgbtRed = (int) avrg;
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE row_reflect[width];
    int h = height;

    if (h < 0) //End case
    {
        return;
    }

    reflect(h-1, width, image); // Do the reflect for only 1 row, and repeat to the next.
    for (int w = 0; w < width; w++) //Copy row inverted to a new array.
    {
        row_reflect[width-1-w] = image[h][w];
    }
    for (int w = 0; w < width; w++) //Reassign to the image itself.
    {
        image[h][w]=row_reflect[w];
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copyimage;
    // As it changes image[height][width] (that is already a copy), it changes input for next calculation.
    // Therefore we need a second image[height][width] to be used as a non-changed image.

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copyimage[h][w] = image[h][w]
        }
    }

    float sumBlue;
    float sumGreen;
    float sumRed;

    // int h = height;
    int count;

    // if (h < 0)
    // {
    //     return;
    // }

    //blur(h-1, width, image); It can`t be recursive because everytime you call it, it will have a new height, then changing boudaries.
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++) // Setting position to calculate blur. //It is gicing segmentation fault because of boundaries. There is no h = -1.
        {
            sumBlue = 0; sumGreen = 0; sumRed = 0; //Setting zero to start a new group
            // group_Blur.rgbtBlue = 0; group_Blur.rgbtGreen = 0; group_Blur.rgbtRed = 0;

            count = 0;

            for (int i = -1; i <= 1; i++) // Iterating surroundings on each position. // Está como se a ordem dos loops estivesse errada. Confere?
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (h+i >= 0 && h+i < height && w+j >= 0 && w+j < width)
                    {
                    // group_Blur.rgbtBlue += image[h+i][w+j].rgbtBlue;
                    // group_Blur.rgbtGreen += image[h+i][w+j].rgbtGreen;
                    // group_Blur.rgbtRed += image[h+i][w+j].rgbtRed;

                    sumBlue += image[h+i][w+j].rgbtBlue;
                    sumGreen += image[h+i][w+j].rgbtGreen;
                    sumRed += image[h+i][w+j].rgbtRed;
                    count++;
                    }
                }
            }

            // image[h][w] = group_Blur / count;

                image[h][w].rgbtBlue = (int) round(avrg_Blue / (float) count);
                image[h][w].rgbtGreen = (int) round(avrg_Green / (float) count);
                image[h][w].rgbtRed = (int) round(avrg_Red / (float) count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}