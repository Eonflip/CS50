#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;

    do
    {
        start_size = get_int("Start Size: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End Size: ");
    }
    while (end_size < 9);

    // TODO: Calculate number of years until we reach threshold
    int years;
    for (years = 0; start_size < end_size; years++){
        start_size = start_size + start_size/3 - start_size/4;
    }



    // TODO: Print number of years
    printf("Years: %i\n", years);
}
