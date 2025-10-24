#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

bool is_jpeg(uint8_t buffer[512]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // opens memory card

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Failed to read file.\n");
        return 1;
    }

    // creates buffer to store blocks

    uint8_t buffer[512];


    // While there's still data left to read from the memory card
    FILE *img = NULL;
    char jpegname[8];
    int count = 0;

    size_t bytesRead = 0;
    while ((bytesRead = fread(buffer, 1, 512, card)) > 0)
    {
        if (is_jpeg(buffer))
        {
            if (img != NULL)
            {
                fclose(img);
                img = NULL;
            }
            // opens new file
            sprintf(jpegname, "%03i.jpg", count);
            img = fopen(jpegname, "w");
            if (img == NULL)
            {
                fprintf(stderr, "Could not create %s\n", jpegname);
                fclose(card);
                return 1;
            }

            count++;
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, bytesRead, img);
        }

    }
    if (img != NULL)
        fclose(img);

    fclose(card);

    return 0;
}

bool is_jpeg(uint8_t buffer[512])
{
    if (   (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) &&
           (buffer[3] == 0xe0 || buffer[3] == 0xe1 || buffer[3] == 0xe2 || buffer[3] == 0xe3 ||
            buffer[3] == 0xe4 || buffer[3] == 0xe5 || buffer[3] == 0xe6 || buffer[3] == 0xe7 ||
            buffer[3] == 0xe8 || buffer[3] == 0xe9 || buffer[3] == 0xea || buffer[3] == 0xeb ||
            buffer[3] == 0xec || buffer[3] == 0xed || buffer[3] == 0xee || buffer[3] == 0xef)   )
    {
        return true;
    }
    return false;
}
