#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int temp_num = 0;
    int counter = strlen(input);

    if (strlen(input) == 0)
    {
        printf("You need to input something!\n");
        return 1;
    }

    for (int i = 0; i <= counter; i++)
    {
        temp_num = temp_num * 10 + (input[i] - '0');
        convert(input);
    }
    return temp_num;


}