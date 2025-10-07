/*
 * FizzBuzz: Prints numbers 1 to 100, replacing multiples of 3 with "Fizz",
 * multiples of 5 with "Buzz", and multiples of both with "FizzBuzz".
 */

#include <stdio.h>

int main () {
    int i = 0;
    for (i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {     
            printf("%d\n", i);
        }
    }
    return 0;
}