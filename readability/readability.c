#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string sentence);
int count_words(string sentence);
int count_sentences(string sentence);

int main(void)
{
    string test_sentence = get_string("Text: ");
    printf("%s\n", test_sentence);

    int grade_level = 0.0588 * float()

    count_letters(test_sentence);
    count_words(test_sentence);
    count_sentences(test_sentence);
}


int count_letters(string sentence)
{
    int num_char = 0;

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (isalnum(sentence[i]))
        {
            num_char += 1;
        }
    }
    return num_char;
}


int count_words(string sentence)
{
    int words = 0;

    for(int i = 0; i <= strlen(sentence); i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\n' || sentence[i] == '\r' || sentence[i] == '\0')
        {
            words++;
        }
    }
    return words;
}


int count_sentences(string sentence)
{
    int sentences = 0;

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}