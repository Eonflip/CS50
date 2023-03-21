#include <cs50.h>
#include <stdio.h>

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

    printf("%ld\n", first_digit);

    if (first_digit == 4 && Math.floor(Math.log10(Math.abs(card_number))) == 13 || 16)
    {
        printf("VISA");
    }
}