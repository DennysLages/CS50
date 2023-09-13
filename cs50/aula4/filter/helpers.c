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
    RGBTRIPLE copyimage[height][width];
    // As it changes image[height][width] (that is already a copy), it changes input for next calculation. Because I`m using same loop to change them.
    // Therefore we need a second image[height][width] to be used as a non-changed image.

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copyimage[h][w] = image[h][w];
        }
    }

    float sumBlue;
    float sumGreen;
    float sumRed;
    int count;

    //blur(h-1, width, image); It can`t be recursive because everytime you call it, it will have a new height, then changing boudaries.

    //Replace pixels by average of surroundings (blur).
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++) // Setting position to calculate blur. //It is gicing segmentation fault because of boundaries. There is no h = -1.
        {
            sumBlue = 0; sumGreen = 0; sumRed = 0; //Setting zero to start a new group
            count = 0;

            for (int i = -1; i <= 1; i++) // Iterating surroundings on each position. // Está como se a ordem dos loops estivesse errada. Confere?
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (h+i >= 0 && h+i < height && w+j >= 0 && w+j < width) //bounderies wrongly set. One case excludes the other wrongly.
                    // if (!(h+i < 0 || h+i >= height || w+j < 0 || w+j >= width))
                    {
                    sumBlue += copyimage[h+i][w+j].rgbtBlue;
                    sumGreen += copyimage[h+i][w+j].rgbtGreen;
                    sumRed += copyimage[h+i][w+j].rgbtRed;
                    count++;
                    }
                }
            }

                //Changing image inside same loop. This is why we have a copy.
                image[h][w].rgbtBlue = (int) round(sumBlue / count);
                image[h][w].rgbtGreen = (int) round(sumGreen / count);
                image[h][w].rgbtRed = (int) round(sumRed / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Variáveis Globais
    RGBTRIPLE copyimage[height][width];
    gx = [-1,0,1][-2,0,2][-1,0,1];
    gy = [-1,-2,-1][0,0,0][1,2,1];

    RGBTRIPLE sumgx;
    RGBTRIPLE sumgy;

    //Loop passando entre cada Pixel e copiando para nova cópia de imagem.
    for (int h; h < height; h++)
    {
        for (int w; w < width; w++)
        {
            copyimage[h][w] = image[h][w];
        }
    }

    ////Loop passando entre cada Pixel para dps calcular os edges.
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // int sumgx = 0; int sumgy = 0; //Ou torna RGBTRIPLE e zera todos os rgb ou cria novos sumgx para cada um do rgb.
            sumgx.rgbtBlue = 0; sumgy.rgbtBlue = 0;
            sumgx.rgbtGreen = 0; sumgy.rgbtGreen = 0;
            sumgx.rgbtRed = 0; sumgy.rgbtRed = 0;

            //Loop calculando gx e gy de cada pixel
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    sumgx += gx[i][j] * copyimage[h+i][w+j].rgbtBlue; sumgy += gy[i][j] * copyimage[h+i][w+j].rgbtBlue;
                    sumgx += gx[i][j] * copyimage[h+i][w+j].rgbtGreen; sumgy += gy[i][j] * copyimage[h+i][w+j].rgbtGreen;
                    sumgx += gx[i][j] * copyimage[h+i][w+j].rgbtRed; sumgy += gy[i][j] * copyimage[h+i][w+j].rgbtRed;
                }
            }
            image[h][w].rgbtBlue = sqrt(sumgx 2 + sumgy 2); //Ver raiz quadrada e elevado
            image[h][w].rgbtGreen = sqrt(sumgx 2 + sumgy 2);
            image[h][w].rgbtRed = sqrt(sumgx 2 + sumgy 2);
        }
    }
    return;
}