#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int Points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int guess_score(string word);

int main(void)
{
    // set input
    string answer1 = get_string("Player 1: ");
    string answer2 = get_string("Player 2: ");
    // compute who wins the scrabble game
    int score1 = guess_score(answer1);
    int score2 = guess_score(answer2);

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
// these for processing
int guess_score(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            // follow ascii; for example, if input words = 'A', then word[0]= 'A', in ascii, 'A'
            // equal to 65, so that it will go on Points[0]
            score += Points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += Points[word[i] - 'a'];
        }
    }
    return score;
}
