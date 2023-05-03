// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

uint8_t wav_header[44];
uint16_t buffer;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    fread(wav_header, sizeof(uint8_t), HEADER_SIZE, input);

    if (wav_header[0] != 'R' || wav_header[1] != 'I' || wav_header[2] != 'F' || wav_header[3] != 'F' ||
        wav_header[8] != 'W' || wav_header[9] != 'A' || wav_header[10] != 'V' || wav_header[11] != 'E')
    {
        printf("Invalid .wav file.\n");
        return 1;
    }

    fwrite(wav_header, sizeof(uint8_t), HEADER_SIZE, output);


    // TODO: Read samples from input file and write updated data to output file
    while (fread(&buffer, sizeof(uint16_t), 1, input))
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(uint16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
