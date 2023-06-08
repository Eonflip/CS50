#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //assign individual pixel to struct value
            RGBTRIPLE pixel = image[i][j];

            //get average of pixel rgb values
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
    //loop through image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //assign value to struct var
            RGBTRIPLE pixel = image[i][j];

            //hold original values for calc later
            int originalRed = pixel.rgbtRed;
            int originalBlue = pixel.rgbtBlue;
            int originalGreen = pixel.rgbtGreen;

            //assign sepia formula for each rgb value
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
    //store data in a variable that mirrors original
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }

    //create 2 arrays to work through pixels surrounding target pixel
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    //loop through image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //create values to store totals and count
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            int count = 0;

            //loop through pixels surrounding target pixel
            for (int k = 0; k < 8; k++)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];

                //conditional statement to make sure the pixel is not outside of image
                if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                {
                    totalRed += original[ni][nj].rgbtRed;
                    totalGreen += original[ni][nj].rgbtGreen;
                    totalBlue += original[ni][nj].rgbtBlue;
                    count++;
                }
            }

            //add original rgb values to the total vars and increment count
            totalRed += original[i][j].rgbtRed;
            totalGreen += original[i][j].rgbtGreen;
            totalBlue += original[i][j].rgbtBlue;
            count++;

            //assign new blue values to the original image 
            image[i][j].rgbtRed = round((float)totalRed / count);
            image[i][j].rgbtGreen = round((float)totalGreen / count);
            image[i][j].rgbtBlue = round((float)totalBlue / count);
        }
    }
    return;
}
