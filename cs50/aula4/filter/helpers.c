#include "helpers.h"
// #include "stdio.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int h = height;
    int avrg = 0;

    if (h == 0) //End case
    {
        return;
    }

    grayscale(h-1, width, image); // Do the grayscale for only 1 row, and repeat to the next.
    for (int w = 0; w < width; w++)
    {
        avrg = (image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3; //Average of each RGBTRIPLE and assign to all bytes (BGR)
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

    if (h == 0) //End case
    {
        return;
    }

    reflect(h-1, width, image); // Do the reflect for only 1 row, and repeat to the next.
    for (int w = 0; w < width; w++) //Copy row inverted to a new array.
    {
        row_reflect[width-w] = image[h][w];
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
    // RGBTRIPLE row_blur[width];
    // RGBTRIPLE column_blur[height];
    // RGBTRIPLE group_blur[2][2];

    // RGBTRIPLE avrg_blur;
    int avrg_Blue;
    int avrg_Green;
    int avrg_Red;
    int h = 1;
    int count;

    if (h == 0)
    {
        return;
    }

    //blur(h-1, width, image); It can`t be recursive because everytime you call it, it will have a new height, then changing boudaries.
    for (h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++) //It is gicing segmentation fault because of boundaries. There is no h = -1.
        {
            avrg_Blue = 0; avrg_Green = 0; avrg_Red = 0; //Setting zero to start a new group


            for (int i = -1; i < 1; i++) // Está como se a ordem dos loops estivesse errada. Confere?
            {
                for (int j = -1; j < 1; j++)
                {
                    count = 0;
                    if (h+i > 0 && h+i < height && w+j > 0 && w+j < width)
                    {
                    avrg_Blue = image[h+i][w+j].rgbtBlue;
                    avrg_Green = image[h+i][w+j].rgbtGreen;
                    avrg_Red = image[h+i][w+j].rgbtRed;
                    count++;
                    }
                }
            }

            image[h][w].rgbtBlue = round(avrg_Blue / count);
            image[h][w].rgbtGreen = round(avrg_Green / count);
            image[h][w].rgbtRed = round(avrg_Red / count);

            // avrg_Blue = round(avrg_Blue / 9);
            // avrg_Green = round(avrg_Green / 9);
            // avrg_Red = round(avrg_Red / 9);

            // image[h][w] = avrg_blur; // Should be copy in entire row at once ?s
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
            /*if (h == 0)
            {
                    for(int i = 0; i < 1; i++)
                    {
                        for(int j = -1; j < 1; j++)
                        {
                            avrg_Blue += image[h+i][w+j].rgbtBlue;
                            avrg_Green += image[h+i][w+j].rgbtGreen;
                            avrg_Red += image[h+i][w+j].rgbtRed;
                        }
                    }

            image[h][w].rgbtBlue = round(avrg_Blue / 6);
            image[h][w].rgbtGreen = round(avrg_Green / 6);
            image[h][w].rgbtRed = round(avrg_Red / 6);
            }

            if (h == height-1)
            {
                    for(int i = -1; i < 0; i++)
                    {
                        for(int j = -1; j < 1; j++)
                        {
                            avrg_Blue += image[h+i][w+j].rgbtBlue;
                            avrg_Green += image[h+i][w+j].rgbtGreen;
                            avrg_Red += image[h+i][w+j].rgbtRed;
                        }
                    }

            image[h][w].rgbtBlue = round(avrg_Blue / 6);
            image[h][w].rgbtGreen = round(avrg_Green / 6);
            image[h][w].rgbtRed = round(avrg_Red / 6);
            }*/

            /*if (w == 0)
            {
                    for(int i = -1; i < 1; i++)
                    {
                        for(int j = -1; j < 1; j++)
                        {
                            avrg_Blue += image[h+i][w+j].rgbtBlue;
                            avrg_Green += image[h+i][w+j].rgbtGreen;
                            avrg_Red += image[h+i][w+j].rgbtRed;
                        }
                    }

            image[h][w].rgbtBlue = round(avrg_Blue / 6);
            image[h][w].rgbtGreen = round(avrg_Green / 6);
            image[h][w].rgbtRed = round(avrg_Red / 6);
            }

            if (w == width-1)
            {
                    for(int i = -1; i < 0; i++)
                    {
                        for(int j = -1; j < 1; j++)
                        {
                            avrg_Blue += image[h+i][w+j].rgbtBlue;
                            avrg_Green += image[h+i][w+j].rgbtGreen;
                            avrg_Red += image[h+i][w+j].rgbtRed;
                        }
                    }

            image[h][w].rgbtBlue = round(avrg_Blue / 6);
            image[h][w].rgbtGreen = round(avrg_Green / 6);
            image[h][w].rgbtRed = round(avrg_Red / 6);
            }*/

            // if(h == 0 || h == height)
            // {
            //     break;
            // }

            // if(w == 0 || w == width)
            // {
            //     break;
            // }