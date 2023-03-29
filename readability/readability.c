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

    float l = (float) count_letters(test_sentence) / (float) count_words(test_sentence) * 100;
    float s = (float) count_sentences(test_sentence) / (float) count_words(test_sentence) * 100;

    int grade_level = round(0.0588 * l - 0.296 * s - 15.8);

    if (grade_level >= 1 && grade_level < 16)
    {
        printf("Grade %i\n", grade_level);
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

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