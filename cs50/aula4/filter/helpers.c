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
    int gx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int gy[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};

    //Loop passando entre cada Pixel e copiando para nova cópia de imagem.
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copyimage[h][w] = image[h][w];
        }
    }

    //Loop passando entre cada Pixel para dps calcular os edges.
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float gxBlue ; float gxGreen; float gxRed; float gyBlue; float gyGreen; float gyRed;
            gxBlue = gxGreen = gxRed = gyBlue = gyGreen = gyRed = 0;

            //Loop calculando gx e gy de cada pixel; No loop mudancas no local do pixel da imagem, dentro mudancas no local do pixel de gx gy.
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int k = i + 1; //Posicoes das matrizes gx gy para cada pixel da matriz original.
                    int l = j + 1;
                    if (h+i >= 0 && h+i < height && w+j >= 0 && w+j < width) //Removing outside bounderies by only calculating inside
                    {
                    gxBlue += gx[k][l] * copyimage[h+i][w+j].rgbtBlue; gyBlue += gy[k][l] * copyimage[h+i][w+j].rgbtBlue;
                    gxGreen += gx[k][l] * copyimage[h+i][w+j].rgbtGreen; gyGreen += gy[k][l] * copyimage[h+i][w+j].rgbtGreen;
                    gxRed += gx[k][l] * copyimage[h+i][w+j].rgbtRed; gyRed += gy[k][l] * copyimage[h+i][w+j].rgbtRed;

                    }
                }
            }
            int blue = round(sqrt(pow(gxBlue, 2) + pow(gyBlue, 2))); //Ver raiz quadrada e elevado
            int green = round(sqrt(pow(gxGreen, 2) + pow(gyGreen, 2)));
            int red = round(sqrt(pow(gxRed, 2) + pow(gyRed, 2)));

            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (red > 255)
            {
                red = 255;
            }
                image[h][w].rgbtBlue = blue;
                image[h][w].rgbtGreen = green;
                image[h][w].rgbtRed = red;
        }
    }
    return;
}