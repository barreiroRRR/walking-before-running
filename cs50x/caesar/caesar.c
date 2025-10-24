#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits(char *key);                    // Function prototype to check digits
char rotate(char letter, int key);

int main(int argc, char *argv[])
{

    bool valid = false;
    if (argc != 2)                              // Discarding num of arguments other than 2
    {
        valid = false;
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        valid = true;
    }

    valid = only_digits(argv[1]);
    if (valid == false || argv[1] == 0)         // Discarding invalid arguments (no digits or 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int k = atoi(argv[1]);                      // Converting argv (char) to int

    //////////////////////////////////

    char *plain = get_string("plaintext: \n");  // Input plaintext
    int len = strlen(plain);
    char *cyph = malloc(sizeof(plain));         // Creating empty cyphertext string with malloc

    printf("ciphertext: ");
    for (int i = 0; i < len; i++)
    {
        cyph[i] = rotate(plain[i], k);          // Implementing function to cyphertext and outpu
        printf("%c", cyph[i]);
    }

    // Output

    printf("\n");
    free(cyph);
}

bool only_digits(char *key)
{
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char letter, int key)
{
    char newlet;
    if (!isalpha(letter)) return letter;

    if (isupper(letter))                    // Uppercase
    {
        newlet = ((letter - 'A' + key) % 26) + 'A';
        return newlet;
    }
    if (islower(letter))                    // Lowercase
    {
        newlet = ((letter - 'a' + key) % 26) + 'a';
        return newlet;
    }
    return 0;
}
