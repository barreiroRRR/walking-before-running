#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // INPUT
    bool valid = true;
    string q1 = NULL;
    string q2 = NULL;

    // VALIDATION PLAYER 1
    do
    {
        valid = true;
        q1 = get_string("Player 1: Question?\r\n");

        if (q1 == NULL || strlen(q1) == 0)
        {
            valid = false;
            continue;
        }
    }
    while (!valid);

    // VALIDATION PLAYER 2
    do
    {
        valid = true;
        q2 = get_string("Player 2: Question?\r\n");

        if (q2 == NULL || strlen(q2) == 0)
        {
            valid = false;
            continue;
        }
    }
    while (!valid);

    // TO UPPER

    for (int up1 = 0; up1 < strlen(q1); up1++)
    {
        q1[up1] = toupper(q1[up1]);
    }
    for (int up2 = 0; up2 < strlen(q2); up2++)
    {
        q2[up2] = toupper(q2[up2]);
    }

    // POINTS FOR EACH LETTER
    char points[][2] =
    {
    {'A', 1},
    {'B', 3},
    {'C', 3},
    {'D', 2},
    {'E', 1},
    {'F', 4},
    {'G', 2},
    {'H', 4},
    {'I', 1},
    {'J', 8},
    {'K', 5},
    {'L', 1},
    {'M', 3},
    {'N', 1},
    {'O', 1},
    {'P', 3},
    {'Q', 10},
    {'R', 1},
    {'S', 1},
    {'T', 1},
    {'U', 1},
    {'V', 4},
    {'W', 4},
    {'X', 8},
    {'Y', 4},
    {'Z', 10}
    };

    // SCORING
    int score1 = 0;
    int score2 = 0;

    for (int k = 0; k < strlen(q1); k++)
    {
        for (int l = 0; l < sizeof(points) / sizeof(points[0]); l++)
        if (q1[k] == points[l][0])
        {
            score1 += points[l][1];
        }
    }
    for (int m = 0; m < strlen(q2); m++)
    {
        for (int n = 0; n < sizeof(points) / sizeof(points[0]); n++)
        if (q2[m] == points[n][0])
        {
            score2 += points[n][1];
        }
    }

    // DETERMINING THE WINNER
    printf("PLAYER 1: %s\nScore: %d\n", q1, score1);
    printf("PLAYER 2: %s\nScore: %d\n", q2, score2);

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

    return 0;
}
