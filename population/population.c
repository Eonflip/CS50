#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    int end_size;
    do
    {
        start_size = get_int("Start Size\n");
    }
    while (start_size < 1);

    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End Size\n");
    }
    while (end_size < 1);

    // TODO: Calculate number of years until we reach threshold
    


    // TODO: Print number of years
}
