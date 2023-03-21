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

    //for loop to create new rows
    for (int i = 0; i < height; i++)
    {
        //for loop to print spaces at the beginning relative height
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        //for loop to print mario blocks
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //for loop to print 2 spaces inbetween the blocks
        for (int j = 1; j < 3; j++)
        {
            printf(" ");
        }
        //for loop to print the mario blocks on the right hand side
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }



}