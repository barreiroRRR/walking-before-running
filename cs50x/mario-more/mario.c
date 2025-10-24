#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int row = get_int("How many rows?\n");
    if (row <= 0)
    {
        row = get_int("How many rows?\n");
    }

    for (int i = 1; i <= row; i++)
    {
        for (int vac = 0; vac < row - i; vac++)
        {
            printf(" ");
        }

        for (int col1 = 0; col1 < i; col1++)
        {
            printf("#");
        }
        printf("  ");
        for (int col2 = 0; col2 < i; col2++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
