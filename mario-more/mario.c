#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    //do-while loop to make sure that the only number accepted is 1-8 inclusive
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //for loop to loop through each column for height entered
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        for (int j = 1; j < 3; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }



}