#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string sentence);

int main(void)
{
    string test_sentence = get_string("Text: ");
    printf("%s\n", test_sentence);

    count_letters(test_sentence);
}


int count_letters(string sentence)
{
    int num_char = 0;

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (isalnum(sentence[i]))
        {
            printf("%c\n", sentence[i]);
            num_char += 1;
        }
    }
    return num_char;
}