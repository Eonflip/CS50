#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;

    do
    {
        start_size = get_int("Start Size\n");
    }
    while (n < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End Size\n");
    }
    while (e < 9);

    // TODO: Calculate number of years until we reach threshold
    int years = 0
    for (int i = 0; n < e; i++){
        n = n + n/3 - n/4;
    }



    // TODO: Print number of years
}
