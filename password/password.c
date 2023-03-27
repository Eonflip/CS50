// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    //initialize all variables to boolean values of false until for loop changes that
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool symbol = false;


    //for loop to iterate through the length of the string (password) and evaluate each char using the ctype library
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            upper = true;
        }
        else if (islower(password[i]))
        {
            lower = true;
        }
        else if (isdigit(password[i]))
        {
            number = true;
        }
        else if (ispunct(password[i]))ls
        {
            symbol = true;
        }
    }

    //if else loop to double check whether or not all bools evalute to true.
    if (upper && lower && number && symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}
