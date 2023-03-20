#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n;
    int e;

    do
    {
        n = get_int("Start Size\n");
    }
    while (n < 9);

    // TODO: Prompt for end size
    do
    {
        e = get_int("End Size\n");
    }
    while (e < 9);

    // TODO: Calculate number of years until we reach threshold
    for (int i = 0; n < e; i++){
        n = n + n/3 - n/4;
    }



    // TODO: Print number of years
}
