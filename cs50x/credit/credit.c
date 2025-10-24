#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // INPUT
    bool valid = true;
    string crednum = NULL;

    do
    {
        valid = true;
        crednum = get_string("Credit card number?\n");

        if (crednum == NULL || strlen(crednum) == 0)
        {
            valid = false;
            continue;
        }
        for (int m = 0; m < strlen(crednum); m++)
        {
            if (crednum[m] < '0' || crednum[m] > '9')
            {
                valid = false;
                break;
            }
        }
    } while (!valid);

    // CHECKSUM
    int len = strlen(crednum);
    int sum = 0;
    int pos = 0;

    for (int i = len - 1; i >= 0; i--, pos++)
    {
        int digit = crednum[i] - '0';

        if (pos % 2 == 1)
        {
            digit = digit * 2;

            if (digit > 9)
            {
                digit = digit - 9;
            }
        }

        sum += digit;
    }

    // CREDIT BRAND
    if (sum % 10 == 0)
    {
        if (((crednum[0] == '3' && crednum[1] == '4') || (crednum[0] == '3' && crednum[1] == '7')) && len == 15)
        {
            printf("AMEX\n");
        }
        else if ((crednum[0] == '5' && (crednum[1] == '1' || crednum[1] == '2' || crednum[1] == '3' || crednum[1] == '4' || crednum[1] == '5')) && len == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (crednum[0] == '4' && ((len == 13) || len == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
