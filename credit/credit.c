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
    long two_digits = card_number;

    while (first_digit >= 10)
    {
        first_digit = first_digit / 10;
    }

    while (two_digits >= 100)
    {
        two_digits = two_digits / 10;
    }

    //print function to test if the first digit is being logged
    printf("%ld\n", two_digits);

    //Test if Visa
    if (first_digit == 4)
    {
        if (floor(log10(labs(card_number))) + 1 == 13)
        {
            printf("VISA\n");
        }
        else if (floor(log10(labs(card_number))) + 1 == 16)
        {
            printf("VISA\n");
        }
    }

    //Test if Amex
    if (first_digit == 34 || first_digit == 37)
    {
        if (floor(log10(labs(card_number))) + 1 == 15)
        {
            printf("AMEX\n");
        }
    }


    //Test if MasterCard
    if (first_digit == 51 || first_digit == 52 || first_digit == 53 || first_digit == 54 || first_digit == 55)
    {
        if (floor(log10(labs(card_number))) + 1 == 13)
        {
            printf("VISA\n");
        }
        else if (floor(log10(labs(card_number))) + 1 == 16)
        {
            printf("VISA\n");
        }
    }


}