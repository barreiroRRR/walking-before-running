/*
 * Date Calculator
 *
 * This program asks the user for a date (mm dd yyyy) and a number of days to add.
 * It then calculates and prints the resulting date, correctly handling:
 * - Different month lengths
 * - Leap years (February = 29 days if leap year, otherwise 28)
 *
 * Note: Only positive day increments are currently supported.
 */

#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0)   return true;
    return false;
}

// Array with days per month (index 0 is unused so that months go 1..12)
int days_in_month[13] = {
    0,  // 0 (not used)
    31, // 1  January
    28, // 2  February (non-leap year)
    31, // 3  March
    30, // 4  April
    31, // 5  May
    30, // 6  June
    31, // 7  July
    31, // 8  August
    30, // 9  September
    31, // 10 October
    30, // 11 November
    31  // 12 December
};

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
    while (days_left_to_add > 0) {
        int dim = days_in_month[*mm];
        if (*mm == 2 && is_leap_year(*yy)) {
            dim = 29; // February in a leap year
        }

        int remaining_in_month = dim - *dd;

        if (days_left_to_add > remaining_in_month) {
            // Move to the first day of the next month
            days_left_to_add -= (remaining_in_month + 1);
            *dd = 1;
            if (*mm == 12) {
                *mm = 1;
                (*yy)++;
            } else {
                (*mm)++;
            }
        } else {
            // All days fit within the current month
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}

int main(void) {
    int mm, dd, yy, days_left_to_add;

    printf("Please enter a date (mm dd yyyy) and the number of days to add:\n");
    if (scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add) != 4) {
        printf("Invalid input.\n");
        return 1;
    }

    add_days_to_date(&mm, &dd, &yy, days_left_to_add);

    printf("Resulting date: %02d/%02d/%04d\n", mm, dd, yy);
    return 0;
}