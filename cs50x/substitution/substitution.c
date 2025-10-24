#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // Your program must accept a single command-line argument, the key to use for the substitution.
    // If your program is executed without any command-line arguments or with more than one command-line argument,
    // your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *key = argv[1];
    int klen = strlen(key);

    // If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character,
    // or not containing each letter exactly once), your program should print an error message of your choice (with printf) and return from main a value of 1 immediately.
    // The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.

    if (klen != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int n = 0; n < klen; n++)
        {
            for (int m = n + 1; m < klen; m++)      // n + 1 para evitar comparar el mismo caracter
            {
                if (tolower(key[n]) == tolower(key[m]))
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }
            }
        }
    }
    for (int i = 0; i < klen; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    // Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).

    char *plaintext = malloc(1000);
    if (plaintext == NULL)
    {
        return 1;
    }
    plaintext = get_string("plaintext: ");

    // Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext,
    // with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext;
    // non-alphabetical characters should be outputted unchanged.
    // Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.

    int plen = strlen(plaintext);
    char *ciphertext = malloc(sizeof(plaintext));
    if (ciphertext == NULL)
    {
        return 1;
    }

    for (int j = 0; j < plen; j++)
    {
        if (!isalpha(plaintext[j]))
        {
            ciphertext[j] = plaintext[j];
        }
        else if (isupper(plaintext[j]))
        {
            ciphertext[j] = toupper(key[plaintext[j] - 'A']);
        }
        else if (islower(plaintext[j]))
        {
            ciphertext[j] = tolower(key[plaintext[j] - 'a']);
        }
    }
    printf("ciphertext: %s\n", ciphertext);
    
    // After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.

    return 0;
}
