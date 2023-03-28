#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    //initialize int to hold sum of character scores
    int scrabble_sum = 0;
    //for loop to convert all characters to lower case (upper case works fine too)
    for(int i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);

        //test is the char at index word[i] is alphanumric and if it is add the score of index of points [index of char]
        if (isalnum(word[i]))
        {
            scrabble_sum += POINTS[word[i] - 97];
        }
    }
    return scrabble_sum;
}

//formula to help identify the arthmetic to get the right char to the right array index
//b -> 98
//98-97 = 1
//POINTS[1]
