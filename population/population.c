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
    while (start_size < 9);

    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End Size\n");
    }
    while (end_size < 9);

    // TODO: Calculate number of years until we reach threshold
    for (i = 0; i < end_size; i++){
        
    }


    // TODO: Print number of years
}
