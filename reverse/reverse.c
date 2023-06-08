#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav");
        return 1;
    }

    char *infile = arg[1];
    char *outfile = argv[2];

    // Open input file for reading
    // TODO #2
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s. \n", infile);
        return 1;
    }
    // Read header
    // TODO #3
    WAVHEADER wh;
    fread(&wh, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    // TODO #4
    bool check_header(WAVHEADER header)
    {
        char expectedFormat[4] = "WAVE";

        for (int i = 0; i < 4; i++)
        {
            if (expectedFormat[i] != header.format[i])
            {
                return false;
            }
        }
        return true;
    }

    // Open output file for writing
    // TODO #5
    FILE *outptr = fopen(outfile, "w");

    // Write header to file
    // TODO #6

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    // TODO #4
    
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}