#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[8][7];

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;
    int inx = 0;

    while (fread(buffer, 7, 8, infile) == 8)
    {
        // Replace '\n' with '\0'
        buffer[inx][6] = '\0';

        // Save plate number in array
        plates[idx] = buffer[inx];
        inx++;
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }
}
