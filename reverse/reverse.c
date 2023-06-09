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
    if (!check_format(wh))
    {
        printf("Input file is not in WAV format. \n");
        fclose(inptr);
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *outptr = fopen(outfile, "w");

    // Write header to file
    // TODO #6
    fwrite(&wh, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int blockSize = get_block_size(wh);
    // Write reversed audio to file
    // TODO #8
    int16_t audio_data;
    fseek(inptr, sizeof(WAVHEADER), SEEK_SET); // Move file pointer to the start of audio data

    int num_samples = wh.subchunk2Size / sizeof(int16_t);

    int16_t *audio_samples = (int16_t*)malloc(num_samples * sizeof(int16_t));
    if (audio_samples == NULL)
    {
        printf("Failed to allocate memory for audio samples. \n");
        fclose(inptr);
        fclose(outptr);
        return 1;
    }

    fread(audio_samples, sizeof(int16_t), num_samples, inptr);

    for (int i = num_samples - 1; i >= 0; i--)
    {
        fwrite(&audio_samples[i], sizeof(int16_t), 1, outptr);
    }
    free(audio_samples);
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
    int sampleSizeBytes = header.bitsPerSample / 8;
    int blockSize = header.numChannels * sampleSizeBytes;
    return blockSize;
}