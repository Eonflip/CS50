#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    long card_number;

    do
    {
        card_number = get_long("Please enter your credit card number: \n");
    }

    while (card_number < 0 || card_number > 5000000000000000);

    long first_digit = card_number;

    while (first_digit >= 10)
    {
        first_digit = first_digit / 10;
    }

    //print function to test if the first digit is being logged 
    //printf("%ld\n", first_digit);

    if (first_digit == 4)
    {
        if (floor(log10(labs(card_number))) == 13)
        {
            printf("VISA");
        }
        else if (floor(log10(labs(card_number))) == 16)
        {
            printf("VISA");
        }
    }


}