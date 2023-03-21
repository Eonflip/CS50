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

    int first_digit = card_number;

    while (first_digit > 10)
    {
        first_digit /= 10;
    }

    printf("%i\n", first_digit);

    //if (card_number[0] == 4 && Math.floor(Math.log10(Math.abs(card_number))) == 13 || 16)
    //{
    //    printf("VISA");
    //}
}