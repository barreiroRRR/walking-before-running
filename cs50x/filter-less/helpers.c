#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int origRed = image[i][j].rgbtRed;
            int origGreen = image[i][j].rgbtGreen;
            int origBlue = image[i][j].rgbtBlue;

            int sepiaRed = (int) round(.393 * origRed + .769 * origGreen + .189 * origBlue);
            int sepiaGreen = (int) round(.349 * origRed + .686 * origGreen + .168 * origBlue);
            int sepiaBlue = (int) round(.272 * origRed + .534 * origGreen + .131 * origBlue);

            if (sepiaRed > 255) sepiaRed = 255;
            if (sepiaGreen > 255) sepiaGreen = 255;
            if (sepiaBlue > 255) sepiaBlue = 255;

            image[i][j].rgbtRed = (BYTE) sepiaRed;
            image[i][j].rgbtGreen = (BYTE) sepiaGreen;
            image[i][j].rgbtBlue = (BYTE) sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < (width / 2); j++)
        {
            tmp[i][j] = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp[i][j];
        }
    }

    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];

    // Recorremos cada píxel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            int count = 0;

            // Recorremos los vecinos (3x3)
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Comprobamos que el vecino esté dentro de los límites
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        totalRed += image[ni][nj].rgbtRed;
                        totalGreen += image[ni][nj].rgbtGreen;
                        totalBlue += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            tmp[i][j].rgbtRed = round(totalRed / (float) count);
            tmp[i][j].rgbtGreen = round(totalGreen / (float) count);
            tmp[i][j].rgbtBlue = round(totalBlue / (float) count);
        }
    }

    // Copiamos el resultado al array original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }

    return;
}
