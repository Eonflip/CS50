#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            char average = (pixel.rgbtRed + pixel.rgbtBlue + pixel.rgbtGreen) / 3.0;

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            int originalRed = pixel.rgbtRed;
            int originalBlue = pixel.rgbtBlue;
            int originalGreen = pixel.rgbtGreen;

            image[i][j].rgbtRed = (uint8_t) fmin((.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue),255.0);
            image[i][j].rgbtGreen = (uint8_t) fmin((.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue),255.0);
            image[i][j].rgbtBlue = (uint8_t) fmin((.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue),255.0);

        }
    }
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
