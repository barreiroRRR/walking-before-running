#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Input text
    char *input = get_string("Text: \n");

    // Count letters, words and sentences
    int wcount = 1;
    int scount = 0;
    int lcount = 0;
    int len = strlen(input); // keep an eye on the escape character "\0"

    for (int w = 0; w < len; w++)
    {
        if (input[w] == ' ')
        {
            wcount++;
        }
        else if (input[w] == '.' || input[w] == '?' || input[w] == '!')
        {
            scount++;
        }
        else if (isalpha(input[w]))
        {
            lcount++;
        }
    }

    // Coleman-Liau index implementation | index = 0.0588 * L - 0.296 * S - 15.8

    float let = ((float) lcount / wcount) * 100;    // L = average number of letters per 100 words in the text.
    float sen = ((float) scount / wcount) * 100;    // S = average number of sentences per 100 words in the text.

    float index = 0.0588 * let - 0.296 * sen - 15.8;

    // Round index

    int index_round = (int) round(index);

    // Output
    if (index_round < 1)                        // Before grade 1
    {
        printf("Before Grade 1\n");
    }
    else if (index_round > 16)                  // Grade over 16
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index_round);      // General output
    }
}
