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

    while (card_number < 0 || card_number > 50000000000000000);

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
    //printf("%ld\n", two_digits);

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
        else
        {
            printf("INVALID\n");
        }
    }

    //Test if Amex
    else if (two_digits == 34 || two_digits == 37)
    {
        if (floor(log10(labs(card_number))) + 1 == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }


    //Test if MasterCard
    else if (two_digits == 51 || two_digits == 52 || two_digits == 53 || two_digits == 54 || two_digits == 55)
    {
        if (floor(log10(labs(card_number))) + 1 == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }

    else
    {
        printf("INVALID\n");
    }


     //int card_number = get_long("Please enter your card number: \n");
    int sum = 0;

    long number = n;

    sum = number % 10;

    number = number / 10;

    while(card_number != 0)
    {

        long digit = ((card_number/10) % 10) * 2;
        card_number = card_number / 100;
        if (digit > 9)
        {
            digit = digit - 9;
        }
        sum = sum + temp;
        number = number / 10;
        digit = number % 10;
        sum = sum + digit;
        number = number / 10;
        //printf("%ld\n", card_number);
        printf("%ld\n", digit);
    }

    while (n > 10)
    {
        n = n / 10;
    }


    printf("Sum: %d\nLeftmost: %ld\n", sum n);

    if (sum % 10)
    {
        return -1;
    }
    return n;




}



