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

    switch(grade_level)
    {
        case 1:
            printf("Grade 1\n");
            break;
        case 2:
            printf("Grade 2\n");
            break;
        case 3:
            printf("Grade 3\n");
            break;
        case 4:
            printf("Grade 4\n");
            break;
        case 5:
            printf("Grade 5\n");
            break;
        case 6:
            printf("Grade 6\n");
            break;
        case 7:
            printf("Grade 7\n");
            break;
        case 8:
            printf("Grade 8\n");
            break;
        case 1:
            printf("Grade 1\n");
            break;
        case 1:
            printf("Grade 1\n");
            break;
        case 1:
            printf("Grade 1\n");
            break;
        case 1:
            printf("Grade 1\n");
            break;
        case 1:
            printf("Grade 1\n");
            break;
        case 1:
            printf("Grade 1\n");
            break;
        case 1:
            printf("Grade 1\n");
            break;
        case 1:
            printf("Grade 1\n");
            break;
    }



    printf("%i\n", grade_level);
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