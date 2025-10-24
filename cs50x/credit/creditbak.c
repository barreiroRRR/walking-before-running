#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string crednum = get_string("Credit card number?\n");

    for (int l = 0; l < strlen(crednum); l++)
    {
        if (crednum[l] < 48 || crednum[l] > 57)
        {
            printf("INVALID\n");
            crednum = get_string("Credit card number?\n");
        }
    }

    string everyother1 = malloc(32);
    string everyother2 = malloc(32);

    for (int i = strlen(crednum) - 1; i > 0; i--)
    {
        if (i % 2 == 0)
        {
            everyother1[i] = crednum[i];
        }
        else
        {
            everyother2[i] = crednum[i];
        }
    }
    int ev_sum_1 = 0;
    int ev_sum_2 = 0;
    for (int j = 0; j < strlen(everyother1); j++)
    {
        everyother1[j] *= 2;
        ev_sum_1 += everyother1[j];
    }
    for (int k = 0; k < strlen(everyother2); k++)
    {
        ev_sum_2 += everyother2[k];
    }
    int total_sum = ev_sum_1 + ev_sum_2;

    if (total_sum % 10 == 0)
    {
        if ((crednum[0] == '3' && crednum[1] == '4') || (crednum[0] == '3' && crednum[1] == '7'))
        {
            printf("AMEX\n");
        }
        else if (crednum[0] == '5' && (crednum[1] == '1' || crednum[1] == '2' || crednum[1] == '3' || crednum[1] == '4' || crednum[1] == '5'))
        {
            printf("MASTERCARD\n");
        }
        else if (crednum[0] == '4')
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    free(everyother1);
    free(everyother2);
    return 0;
}
