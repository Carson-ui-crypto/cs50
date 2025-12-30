#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    int letter = 0, word = 1, sentense = 0;
    // check the sentenses that consists of how many letters, words, and sentenses
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter += 1;
        }
        else if (text[i] == ' ')
        {
            word += 1;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentense += 1;
        }
    }
    // compute the Coleman-Liau index
    float L = ((float) letter / (float) word) * 100;
    float S = ((float) sentense / (float) word) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade_score = round(index);
    // check grade level
    if (grade_score > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_score < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade_score);
    }
}
