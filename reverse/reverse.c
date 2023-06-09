#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "wav.h"

bool check_format(WAVHEADER header);
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

    char *infile = argv[1];
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
    check_format(wh);

    // Open output file for writing
    // TODO #5
    FILE *outptr = fopen(outfile, "w");

    // Write header to file
    // TODO #6
    fwrite(&wh, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    get_block_size(wh);
    // Write reversed audio to file
    // TODO #8
    int16_t audio_data;
    fseek(inptr, sizeof(WAVHEADER), SEEK_SET); // Move file pointer to the start of audio data

    while (fread(&audio_data, sizeof(int16_t), 1, inptr) == 1)
    {
        fwrite(&audio_data, sizeof(int16_t), 1, outptr);
    }
    fclose(inptr);
    fclose(outptr);
}

bool check_format(WAVHEADER header)
{
    // TODO #4
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

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int blockSize = header.numChannels * header.subchunk2Size;
    return blockSize;
}