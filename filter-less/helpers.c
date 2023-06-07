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

            char average = round((pixel.rgbtRed + pixel.rgbtBlue + pixel.rgbtGreen) / 3.00);

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

            image[i][j].rgbtRed = (uint8_t) round(fmin((.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue),255.0));
            image[i][j].rgbtGreen = (uint8_t) round(fmin((.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue),255.0));
            image[i][j].rgbtBlue = (uint8_t) round(fmin((.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue),255.0));

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, 1, -1, 0, 1};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            int count = 0;

            for (int k = 0; k < 8; k++)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                {
                    totalRed += original[ni][nj].rgbtRed;
                    totalGreen += original[ni][nj].rgbtGreen;
                    totalBlue += original[ni][nj].rgbtBlue;
                    count++;
                }
            }

            totalRed += original[i][j].rgbtRed;
            totalGreen += original[i][j].rgbtGreen;
            totalBlue += original[i][j].rgbtBlue;
            count++;

            image[i][j].rgbtRed = round(totalRed / count);
            image[i][j].rgbtGreen = round(totalGreen / count);
            image[i][j].rgbtBlue = round(totalBlue / count);
        }
    }
    return;
}
